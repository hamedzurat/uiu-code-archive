CREATE TRIGGER TrgAfterInsert
ON employee
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO employeeLog (empid, logmsg)
    SELECT
        id,
        CONCAT('Employee ', name, ' inserted with salary ', salary)
    FROM inserted;
END
