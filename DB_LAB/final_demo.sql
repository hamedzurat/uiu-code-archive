-- FARMS Table
CREATE TABLE FARMS (
    farm_id VARCHAR(10) PRIMARY KEY,
    farm_name VARCHAR(50) NOT NULL,
    location VARCHAR(50) NOT NULL,
    area_acres INT NOT NULL
);

-- CROPS Table
CREATE TABLE CROPS (
    crop_id VARCHAR(10) PRIMARY KEY,
    crop_name VARCHAR(50) NOT NULL,
    category VARCHAR(30) NOT NULL,
    season VARCHAR(20) NOT NULL
);

-- EMPLOYEES Table
CREATE TABLE EMPLOYEES (
    emp_id VARCHAR(10) PRIMARY KEY,
    emp_name VARCHAR(50) NOT NULL,
    farm_id VARCHAR(10) NULL,
    designation VARCHAR(30) NOT NULL,
    salary DECIMAL(10, 2) NOT NULL,
    join_date DATE NOT NULL,
    FOREIGN KEY (farm_id) REFERENCES FARMS (farm_id)
);

-- PRODUCTION Table
CREATE TABLE PRODUCTION (
    prod_id VARCHAR(10) PRIMARY KEY,
    farm_id VARCHAR(10) NOT NULL,
    crop_id VARCHAR(10) NOT NULL,
    year INT NOT NULL,
    quantity_ton DECIMAL(10, 2) NOT NULL,
    production_cost DECIMAL(12, 2) NOT NULL,
    FOREIGN KEY (farm_id) REFERENCES FARMS (farm_id),
    FOREIGN KEY (crop_id) REFERENCES CROPS (crop_id)
);

-- SALES Table
CREATE TABLE SALES (
    sale_id VARCHAR(10) PRIMARY KEY,
    prod_id VARCHAR(10) NOT NULL,
    sale_date DATE NOT NULL,
    quantity_sold DECIMAL(10, 2) NOT NULL,
    unit_price DECIMAL(10, 2) NOT NULL,
    buyer_name VARCHAR(50) NOT NULL,
    payment_status VARCHAR(20) NOT NULL,
    FOREIGN KEY (prod_id) REFERENCES PRODUCTION (prod_id)
);

GO
-- Insert into FARMS
INSERT INTO FARMS (farm_id, farm_name, location, area_acres)
VALUES
    ('F001', 'Sunrise Farm', 'Rajshahi', 450),
    ('F002', 'Golden Fields', 'Dinajpur', 380),
    ('F003', 'Green Valley', 'Bogra', 520),
    ('F004', 'River Bank Farm', 'Rangpur', 290),
    ('F005', 'Horizon Acres', 'Jessore', 410);

-- Insert into CROPS
INSERT INTO CROPS (crop_id, crop_name, category, season)
VALUES
    ('C001', 'Boro Rice', 'Cereal', 'Winter'),
    ('C002', 'Aman Rice', 'Cereal', 'Monsoon'),
    ('C003', 'Wheat', 'Cereal', 'Winter'),
    ('C004', 'Potato', 'Vegetable', 'Winter'),
    ('C005', 'Tomato', 'Vegetable', 'Winter'),
    ('C006', 'Mango', 'Fruit', 'Summer'),
    ('C007', 'Jute', 'Fiber', 'Monsoon');

-- Insert into EMPLOYEES
INSERT INTO EMPLOYEES (emp_id, emp_name, farm_id, designation, salary, join_date)
VALUES
    ('E001', 'Karim Uddin', 'F001', 'Farm Manager', 45000, '2018-03-15'),
    ('E002', 'Rahim Ahmed', 'F001', 'Supervisor', 28000, '2019-06-20'),
    ('E003', 'Fatema Begum', 'F002', 'Farm Manager', 42000, '2017-01-10'),
    ('E004', 'Jamal Hossain', 'F002', 'Field Worker', 15000, '2020-08-05'),
    ('E005', 'Nasreen Akter', 'F003', 'Supervisor', 30000, '2019-11-12'),
    ('E006', 'Belal Khan', 'F003', 'Field Worker', 16000, '2021-02-28'),
    ('E007', 'Shirin Sultana', 'F004', 'Farm Manager', 40000, '2018-09-01'),
    ('E008', 'Mostafa Ali', NULL, 'Consultant', 55000, '2022-01-15');

-- Insert into PRODUCTION
INSERT INTO PRODUCTION (prod_id, farm_id, crop_id, year, quantity_ton, production_cost)
VALUES
    ('P001', 'F001', 'C001', 2024, 850, 425000),
    ('P002', 'F001', 'C004', 2024, 320, 192000),
    ('P003', 'F002', 'C001', 2024, 720, 360000),
    ('P004', 'F002', 'C003', 2024, 450, 225000),
    ('P005', 'F003', 'C002', 2024, 680, 340000),
    ('P006', 'F003', 'C005', 2024, 180, 126000),
    ('P007', 'F004', 'C006', 2024, 95, 76000),
    ('P008', 'F001', 'C001', 2023, 780, 390000),
    ('P009', 'F002', 'C001', 2023, 650, 325000),
    ('P010', 'F003', 'C007', 2024, 420, 168000);

-- Insert into SALES
INSERT INTO SALES (sale_id, prod_id, sale_date, quantity_sold, unit_price, buyer_name, payment_status)
VALUES
    ('S001', 'P001', '2024-04-15', 400, 52000, 'City Traders Ltd', 'Paid'),
    ('S002', 'P001', '2024-05-20', 300, 54000, 'National Foods', 'Paid'),
    ('S003', 'P002', '2024-03-10', 200, 35000, 'Fresh Mart', 'Pending'),
    ('S004', 'P003', '2024-04-25', 500, 51000, 'City Traders Ltd', 'Paid'),
    ('S005', 'P004', '2024-05-05', 300, 42000, 'Grain House', 'Paid'),
    ('S006', 'P005', '2024-10-18', 400, 48000, 'National Foods', 'Pending'),
    ('S007', 'P006', '2024-02-28', 100, 65000, 'Fresh Mart', 'Paid'),
    ('S008', 'P007', '2024-06-15', 60, 120000, 'Export Corp', 'Paid'),
    ('S009', 'P010', '2024-09-20', 350, 55000, 'Jute Mills Ltd', 'Pending'),
    ('S010', 'P003', '2024-06-10', 150, 53000, 'Grain House', 'Paid');

GO
-- Check record counts in all tables
SELECT
    'FARMS' AS table_name,
    COUNT(*) AS record_count
FROM
    FARMS
UNION ALL
SELECT
    'CROPS',
    COUNT(*)
FROM
    CROPS
UNION ALL
SELECT
    'EMPLOYEES',
    COUNT(*)
FROM
    EMPLOYEES
UNION ALL
SELECT
    'PRODUCTION',
    COUNT(*)
FROM
    PRODUCTION
UNION ALL
SELECT
    'SALES',
    COUNT(*)
FROM
    SALES;

-- Expected Output:
-- FARMS: 5 records
-- CROPS: 7 records
-- EMPLOYEES: 8 records
-- PRODUCTION: 10 records
-- SALES: 10 records
-- 1
SELECT
    e.emp_name,
    e.designation,
    f.farm_name,
    f.location
FROM
    EMPLOYEES e
    JOIN FARMS f ON e.farm_id = f.farm_id
ORDER BY
    f.farm_name ASC;

-- 2
SELECT
    e.emp_id,
    e.emp_name,
    e.designation,
    e.salary,
    ISNULL (f.farm_name,
        'Unassigned') AS farm_name
FROM
    EMPLOYEES e
    LEFT JOIN FARMS f ON e.farm_id = f.farm_id;

-- 3
SELECT
    COUNT(*) AS total_records,
    SUM(quantity_ton) AS total_quantity,
    AVG(quantity_ton) AS avg_quantity,
    MAX(quantity_ton) AS max_quantity,
    MIN(quantity_ton) AS min_quantity,
    SUM(production_cost) AS total_cost
FROM
    PRODUCTION
WHERE
    year = 2024;

-- 4
SELECT
    f.farm_name,
    SUM(p.quantity_ton) AS total_production
FROM
    FARMS f
    JOIN PRODUCTION p ON f.farm_id = p.farm_id
WHERE
    p.year = 2024
GROUP BY
    f.farm_name
HAVING
    SUM(p.quantity_ton) > 500
ORDER BY
    total_production DESC;

-- 5
SELECT
    emp_name,
    designation,
    salary,
    CASE WHEN salary >= 40000 THEN
        'Grade A - Executive'
    WHEN salary >= 25000
        AND salary < 40000 THEN
        'Grade B - Senior Staff'
    WHEN salary >= 15000
        AND salary < 25000 THEN
        'Grade C - Junior Staff'
    ELSE
        'Grade D - Trainee'
    END AS salary_grade
FROM
    EMPLOYEES;

-- 6
SELECT
    emp_id,
    UPPER(emp_name) AS upper_name,
    LEFT (emp_name,
        3) AS name_code,
    LEN (emp_name) AS name_length,
    CONCAT(emp_id, '-', UPPER(emp_name)) AS id_card_number
FROM
    EMPLOYEES;

-- 7
SELECT
    s.sale_id,
    c.crop_name,
    f.farm_name,
    s.sale_date,
    s.quantity_sold,
    (s.quantity_sold * s.unit_price) AS total_sale_value,
    DATENAME (MONTH, s.sale_date) AS sale_month
FROM
    SALES s
    JOIN PRODUCTION p ON s.prod_id = p.prod_id
    JOIN CROPS c ON p.crop_id = c.crop_id
    JOIN FARMS f ON p.farm_id = f.farm_id
WHERE
    s.sale_date BETWEEN '2024-01-01' AND '2024-06-30';

-- 8
SELECT
    buyer_name,
    COUNT(*) AS purchase_count,
    SUM(quantity_sold) AS total_quantity,
    SUM(quantity_sold * unit_price) AS total_amount,
    AVG(quantity_sold * unit_price) AS avg_purchase,
    CASE WHEN SUM(quantity_sold * unit_price) >= 25000000 THEN
        'Platinum Buyer'
    WHEN SUM(quantity_sold * unit_price) >= 15000000 THEN
        'Gold Buyer'
    ELSE
        'Silver Buyer'
    END AS buyer_category
FROM
    SALES
GROUP BY
    buyer_name
HAVING
    COUNT(*) >= 2
ORDER BY
    total_amount DESC;

