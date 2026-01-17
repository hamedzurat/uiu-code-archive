USE SkyWingsAirlines;

-- CREATE PROCEDURE zurat_0112330113 AS
ALTER PROCEDURE zurat_0112330113 AS
BEGIN
    -- DEBUG
    SELECT * FROM Aircraft;
    SELECT * FROM Airports;
    SELECT * FROM Bookings;
    SELECT * FROM Flights;
    SELECT * FROM Passengers;

    -- 1
    SELECT
        f.FlightNumber,
        CASE
            WHEN p.FirstName IS NULL THEN 'NULL'
            ELSE CONCAT(p.FirstName, ' ', p.LastName)
        END AS PassengerName,
        CASE
            WHEN b.BookingStatus = 'Confirmed' THEN 'Active Booking'
            WHEN b.BookingStatus = 'Cancelled' THEN 'Cancelled'
            WHEN b.BookingStatus = 'Pending' THEN 'Pending'
            ELSE 'No Booking'
        END AS BookingCategory
    FROM Bookings b
    FULL JOIN Passengers p ON b.PassengerID = p.PassengerID
    FULL JOIN Flights f ON b.FlightID = f.FlightID;

    -- 2
    SELECT
        a.City,
        COUNT(f.DepartureAirportID) AS DepartingFlight
    FROM Flights f
    INNER JOIN Airports a ON f.DepartureAirportID = a.AirportID
    GROUP BY a.City
    HAVING COUNT(f.DepartureAirportID) > 1;

    -- 3
    -- to make .67 not .6667
    DECLARE @avg DECIMAL(10, 2) = (SELECT AVG(TicketPrice) FROM Flights);
    SELECT
        f.FlightNumber AS FlighNumber,
        f.TicketPrice,
        (f.TicketPrice - @avg) AS DifferenceFromAvg
    FROM Flights f
    WHERE f.TicketPrice > (SELECT AVG(TicketPrice) FROM Flights);

    -- 4
    SELECT
        'Seat Class' AS Category,
        b.SeatClass AS Type,
        COUNT(*) AS Count
    FROM Bookings b
    GROUP BY b.SeatClass
    UNION
    SELECT
        'Membership' AS Category,
        COALESCE(p.MembershipLevel, 'No Membership') AS Type,
        COUNT(p.Email) AS Count
    FROM Passengers p
    GROUP BY p.MembershipLevel
    ORDER BY Category;

END;
