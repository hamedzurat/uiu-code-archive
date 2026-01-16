CREATE TRIGGER DeletPreventionTrg
ON employee
INSTEAD OF DELETE
AS
BEGIN
    RAISERROR ('Deletion cant be allowed', 16, 1);
END
