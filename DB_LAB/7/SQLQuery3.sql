USE zurat_petcare;

SELECT
    *
FROM
    employee;

SELECT
    l.logid,
    e.name,
    l.logdate,
    l.logmsg
FROM
    employeeLog l
    JOIN employee e ON l.empid = e.id;

