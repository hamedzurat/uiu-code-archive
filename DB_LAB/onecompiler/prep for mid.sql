USE zurat_petcare;


/* =========================================================
 ONE-STOP SQL SERVER NOTES (Easy Online Shop Example)
 You can run this whole script in OneCompiler and read output
 step-by-step. Every query has a clear description.

 Topics covered (simple + practical):
 - Tables + PK/FK
 - ON DELETE CASCADE
 - Direct INSERT sample data
 - SELECT * to see all tables
 - Filtering (WHERE), Sorting (ORDER BY), LIKE
 - VIEW (saved join)
 - JOIN types: INNER, LEFT, RIGHT, FULL OUTER, CROSS
 - DISTINCT
 - Aggregates: COUNT, COUNT DISTINCT, SUM, AVG, MIN, MAX
 - GROUP BY, HAVING
 ========================================================= */
------------------------------------------------------------
-- 0) reset
------------------------------------------------------------
DROP TABLE OrderItem;

DROP TABLE Payment;

DROP TABLE OrderHeader;

DROP TABLE Product;

DROP TABLE Customer;

------------------------------------------------------------
-- 1) TABLES
------------------------------------------------------------
-- Customers
CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,
    FullName VARCHAR(60) NOT NULL,
    City VARCHAR(40) NOT NULL
);

-- Products
CREATE TABLE Product (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(60) NOT NULL,
    Category VARCHAR(30) NOT NULL,
    UnitPrice Decimal(10, 2) NOT NULL
);

-- Orders (header)
-- ON DELETE CASCADE: deleting a customer deletes their orders automatically
CREATE TABLE OrderHeader (
    OrderID INT PRIMARY KEY,
    CustomerID INT NOT NULL,
    OrderDate DATE NOT NULL,
    Status VARCHAR(15) NOT NULL, -- Placed / Shipped / Cancelled
    CONSTRAINT FK_OrderHeader_Customer FOREIGN KEY (CustomerID) REFERENCES Customer (CustomerID) ON DELETE CASCADE
);

-- Order items (line items)
-- ON DELETE CASCADE: deleting an order deletes its order items automatically
CREATE TABLE OrderItem (
    OrderID INT NOT NULL,
    ProductID INT NOT NULL,
    Qty INT NOT NULL,
    UnitPrice Decimal(10, 2) NOT NULL, -- price snapshot at purchase time
    CONSTRAINT PK_OrderItem PRIMARY KEY (OrderID, ProductID),
    CONSTRAINT FK_OrderItem_Order FOREIGN KEY (OrderID) REFERENCES OrderHeader (OrderID) ON DELETE CASCADE,
    CONSTRAINT FK_OrderItem_Product FOREIGN KEY (ProductID) REFERENCES Product (ProductID)
);

-- Payments (1 payment per order)
-- ON DELETE CASCADE: deleting an order deletes its payment automatically
CREATE TABLE Payment (
    PaymentID INT PRIMARY KEY,
    OrderID INT NOT NULL UNIQUE,
    PaidAmount Decimal(10, 2) NOT NULL,
    PaidDate DATE NOT NULL,
    Method VARCHAR(15) NOT NULL, -- Card / BKash / Cash
    CONSTRAINT FK_Payment_Order FOREIGN KEY (OrderID) REFERENCES OrderHeader (OrderID) ON DELETE CASCADE
);

GO;

------------------------------------------------------------
-- 2) SAMPLE DATA (small but expressive)
------------------------------------------------------------
INSERT INTO Customer
VALUES
    (1, 'Ayaan Hossain', 'Dhaka'),
    (2, 'Nadia Islam', 'Dhaka'),
    (3, 'Rafi Uddin', 'Chattogram'),
    (4, 'Mitu Rahman', 'Sylhet'),
    (5, 'Fahim Chowdhury', 'Dhaka');

-- has no orders (useful for LEFT JOIN)
INSERT INTO Product
VALUES
    (101, 'Wireless Mouse', 'Electronics', 800.00),
    (102, 'Mechanical Keyboard', 'Electronics', 3500.00),
    (103, 'Coffee Beans 1kg', 'Grocery', 1200.00),
    (104, 'Notebook A5', 'Stationery', 120.00),
    (105, 'Water Bottle', 'Stationery', 450.00);

-- never sold (useful for RIGHT JOIN)
INSERT INTO OrderHeader
VALUES
    (5001, 1, '2025-11-01', 'Placed'),
    (5002, 1, '2025-11-05', 'Shipped'),
    (5003, 2, '2025-11-07', 'Cancelled'),
    (5004, 3, '2025-11-10', 'Placed');

-- not paid yet
INSERT INTO OrderItem
VALUES
    (5001, 101, 2, 800.00),
    (5001, 104, 5, 120.00),
    (5002, 102, 1, 3500.00),
    (5002, 101, 1, 780.00), -- snapshot price differs (realistic)
    (5003, 103, 1, 1200.00),
    (5004, 104, 10, 120.00);

INSERT INTO Payment
    VALUES (9001, 5001, 2200.00, '2025-11-01', 'Card'), -- 2*800 + 5*120 = 2200
    (9002, 5002, 4280.00, '2025-11-05', 'BKash');

-- 3500 + 780 = 4280
-- Note: order 5003 is Cancelled (no payment), 5004 not paid yet
GO;

------------------------------------------------------------
-- 3) QUICK "SEE EVERYTHING" (SELECT * from all tables)
-- Purpose: let you visually understand the sample data first.
------------------------------------------------------------
PRINT '' PRINT '' PRINT '-- *'
SELECT
    *
FROM
    Customer;

SELECT
    *
FROM
    Product;

SELECT
    *
FROM
    OrderHeader;

SELECT
    *
FROM
    OrderItem;

SELECT
    *
FROM
    Payment;

GO;

------------------------------------------------------------
-- 4) FILTERING, SORTING, LIKE (simple basics)
------------------------------------------------------------
PRINT '' PRINT '' PRINT '-- Filtering (WHERE) + Sorting (ORDER BY)'
-- Q1) Filtering (WHERE) + Sorting (ORDER BY)
-- "Show customers only from Dhaka, sorted by name A->Z"
SELECT
    CustomerID,
    FullName,
    City
FROM
    Customer
WHERE
    City = 'Dhaka'
ORDER BY
    FullName ASC;

PRINT '' PRINT '' PRINT '--  LIKE (pattern search)'
-- Q2) LIKE (pattern search)
-- "Find products whose name contains 'Note' (case-insensitive depends on collation)"
SELECT
    ProductID,
    ProductName,
    Category,
    UnitPrice
FROM
    Product
WHERE
    ProductName LIKE '%Note%'
ORDER BY
    UnitPrice DESC;

PRINT '' PRINT '' PRINT '-- Filtering with multiple conditions (AND/OR)'
-- Q3) Filtering with multiple conditions (AND/OR)
-- "Show only orders that are Placed OR Shipped, newest first"
SELECT
    OrderID,
    CustomerID,
    OrderDate,
    Status
FROM
    OrderHeader
WHERE
    Status IN ('Placed', 'Shipped')
ORDER BY
    OrderDate DESC;

GO;

------------------------------------------------------------
-- 5) VIEW (saved JOIN)
-- Purpose: hides repeated join logic, makes reporting easier.
-- IMPORTANT: CREATE VIEW must be first statement in its batch => we used GO above.
------------------------------------------------------------
CREATE VIEW vOrderLineDetails AS
SELECT
    oh.OrderID,
    oh.OrderDate,
    oh.Status AS OrderStatus,
    c.CustomerID,
    c.FullName,
    c.City,
    p.ProductID,
    p.ProductName,
    p.Category,
    oi.Qty,
    oi.UnitPrice,
    (oi.Qty * oi.UnitPrice) AS LineTotal
FROM
    OrderHeader oh
    JOIN Customer c ON c.CustomerID = oh.CustomerID
    JOIN OrderItem oi ON oi.OrderID = oh.OrderID
    JOIN Product p ON p.ProductID = oi.ProductID;

GO;

------------------------------------------------------------
-- 6) JOIN TYPES (explained + easy to read)
------------------------------------------------------------
PRINT '' PRINT '' PRINT '-- INNER JOIN'
-- Q4) INNER JOIN
-- Rule: returns ONLY matching rows in both sides.
-- Meaning here: "Show only orders that actually have items"
SELECT
    OrderID,
    FullName,
    ProductName,
    Qty,
    UnitPrice,
    LineTotal
FROM
    vOrderLineDetails
ORDER BY
    OrderID,
    ProductName;

PRINT '' PRINT '' PRINT '-- LEFT JOIN'
-- Q5) LEFT JOIN
-- Rule: keep ALL rows from LEFT table; missing matches become NULL on right.
-- Meaning here: "Show ALL customers, even those with NO orders"
SELECT
    c.CustomerID,
    c.FullName,
    c.City,
    oh.OrderID,
    oh.OrderDate,
    oh.Status
FROM
    Customer c
    LEFT JOIN OrderHeader oh ON oh.CustomerID = c.CustomerID
ORDER BY
    c.CustomerID,
    oh.OrderID;

PRINT '' PRINT '' PRINT '-- LEFT JOIN + filtering to find "no match" rows'
-- Q6) LEFT JOIN + filtering to find "no match" rows
-- Meaning: "Which customers have NO orders?"
SELECT
    c.CustomerID,
    c.FullName,
    c.City
FROM
    Customer c
    LEFT JOIN OrderHeader oh ON oh.CustomerID = c.CustomerID
WHERE
    oh.OrderID IS NULL
ORDER BY
    c.CustomerID;

PRINT '' PRINT '' PRINT '-- RIGHT JOIN'
-- Q7) RIGHT JOIN
-- Rule: keep ALL rows from RIGHT table; missing matches become NULL on left.
-- Meaning here: "Show ALL products, even products never sold"
SELECT
    p.ProductID,
    p.ProductName,
    p.Category,
    oi.OrderID AS SoldInOrderID
FROM
    OrderItem oi
    RIGHT JOIN Product p ON p.ProductID = oi.ProductID
ORDER BY
    p.ProductID,
    oi.OrderID;

PRINT '' PRINT '' PRINT '-- RIGHT JOIN + filter to find unsold products'
-- Q8) RIGHT JOIN + filter to find unsold products
-- Meaning: "Which products were NEVER ordered?"
SELECT
    p.ProductID,
    p.ProductName,
    p.Category
FROM
    OrderItem oi
    RIGHT JOIN Product p ON p.ProductID = oi.ProductID
WHERE
    oi.OrderID IS NULL
ORDER BY
    p.ProductID;

PRINT '' PRINT '' PRINT '-- FULL OUTER JOIN'
-- Q9) FULL OUTER JOIN
-- Rule: keep ALL rows from both sides; matches merge, non-matches show NULLs.
-- Meaning: "Show paid + unpaid orders (and would show orphan payments if existed)"
SELECT
    -- COALESCE(oh.OrderID, pay.OrderID) AS OrderID,
    oh.OrderID AS ohID,
    pay.OrderID AS payID,
    oh.Status AS OrderStatus,
    pay.PaidAmount,
    pay.Method,
    CASE WHEN oh.OrderID IS NULL THEN
        'Payment has no order (data issue)'
    WHEN pay.OrderID IS NULL THEN
        'Order not paid yet'
    ELSE
        'Order has payment'
    END AS MatchNote
FROM
    OrderHeader oh
    FULL OUTER JOIN Payment pay ON pay.OrderID = oh.OrderID
-- ORDER BY OrderID;
ORDER BY
    ohID;

PRINT '' PRINT '' PRINT '-- CROSS JOIN'
-- Q10) CROSS JOIN
-- Rule: every combination (cartesian product).
-- Meaning: "Generate every Product x DiscountTier combination"
SELECT
    p.ProductName,
    d.DiscountPct,
    p.UnitPrice AS OriginalPrice,
    p.UnitPrice * (1 - d.DiscountPct / 100.0) AS DiscountedPrice
FROM
    Product p
    CROSS JOIN (
        VALUES (0),
            (5),
            (10),
            (15)) d (DiscountPct)
ORDER BY
    p.ProductName,
    d.DiscountPct;

GO;

------------------------------------------------------------
-- 7) DISTINCT + AGGREGATES (COUNT/SUM/AVG/MIN/MAX) + GROUP BY + HAVING
------------------------------------------------------------
PRINT '' PRINT '' PRINT '-- DISTINCT'
-- Q11) DISTINCT
-- Meaning: "Unique list of cities where customers live"
SELECT DISTINCT
    City
FROM
    Customer
ORDER BY
    City;

PRINT '' PRINT '' PRINT '-- Aggregate per ORDER (total value of each order)'
-- Q12) Aggregate per ORDER (total value of each order)
-- Shows: SUM + GROUP BY
SELECT
    OrderID,
    Sum(LineTotal) AS OrderTotal
FROM
    vOrderLineDetails
GROUP BY
    OrderID
ORDER BY
    OrderTotal DESC;

SELECT
    Sum(LineTotal) AS OrderTotal
FROM
    vOrderLineDetails
ORDER BY
    OrderTotal DESC;

PRINT '' PRINT '' PRINT '-- Aggregate per CUSTOMER (how much each customer spent)'
-- Q13) Aggregate per CUSTOMER (how much each customer spent)
-- Shows: COUNT, COUNT DISTINCT, SUM, AVG, MIN, MAX, GROUP BY, HAVING
-- Note: Cancelled orders are excluded here (common real-world rule)
SELECT
    CustomerID,
    FullName,
    Count(DISTINCT OrderID) AS OrdersCount,
    Count(*) AS LineCount,
    Sum(LineTotal) AS TotalSpent,
    Avg(LineTotal) AS AvgLineValue,
    Min(LineTotal) AS MinLineValue,
    Max(LineTotal) AS MaxLineValue
FROM
    vOrderLineDetails
WHERE
    OrderStatus IN ('Placed', 'Shipped')
GROUP BY
    CustomerID,
    FullName
HAVING
    Sum(LineTotal) >= 500 -- only show customers who spent at least 500
ORDER BY
    TotalSpent DESC;

PRINT '' PRINT '' PRINT '-- Aggregate by CATEGORY'
-- Q14) Aggregate by CATEGORY
-- Shows: SUM, COUNT DISTINCT, GROUP BY
SELECT
    Category,
    Sum(Qty) AS TotalUnitsSold,
    Sum(LineTotal) AS Revenue,
    Count(DISTINCT ProductID) AS DistinctProductsSold
FROM
    vOrderLineDetails
GROUP BY
    Category
ORDER BY
    Revenue DESC;

GO;

------------------------------------------------------------
-- 8) ON DELETE CASCADE DEMO (super important concept)
-- What should happen:
-- - Deleting OrderHeader(5001) will auto-delete:
--   * OrderItem rows for 5001
--   * Payment row for 5001
------------------------------------------------------------
PRINT '' PRINT '' PRINT '-- ON DELETE CASCADE'
-- Before delete: order 5001 exists in OrderItem and Payment
SELECT
    *
FROM
    OrderItem
WHERE
    OrderID = 5001;

SELECT
    *
FROM
    Payment
WHERE
    OrderID = 5001;

-- Delete the parent row (OrderHeader)
DELETE FROM OrderHeader
WHERE OrderID = 5001;

-- After delete: child rows are automatically gone (CASCADE)
SELECT
    *
FROM
    OrderItem
WHERE
    OrderID = 5001;

SELECT
    *
FROM
    Payment
WHERE
    OrderID = 5001;

-- Also confirm the order itself is gone
SELECT
    *
FROM
    OrderHeader
WHERE
    OrderID = 5001;

