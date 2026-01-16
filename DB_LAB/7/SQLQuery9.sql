USE zurat_petcare;

DELETE FROM employee
WHERE id = (
        SELECT
            TOP 1 id
        FROM
            employee
        ORDER BY
            NEWID ());

