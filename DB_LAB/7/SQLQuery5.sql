USE zurat_petcare;

INSERT INTO employee (name, address, salary)
SELECT
    fn.name + ' ' + ln.name,
    'Random City',
    CAST(35000 + (ABS(CHECKSUM (NEWID ())) % 65000) AS DECIMAL(10, 2))
FROM (
    VALUES ('John'),
        ('Jane'),
        ('Michael'),
        ('Emily'),
        ('David'),
        ('Sarah')) fn (name)
    CROSS JOIN (
        VALUES ('Smith'), ('Brown'), ('Johnson'), ('Davis'), ('Wilson'), ('Taylor'))
    ln(name)
ORDER BY
    NEWID ()
    OFFSET 0 ROWS FETCH NEXT 1 ROW ONLY;

