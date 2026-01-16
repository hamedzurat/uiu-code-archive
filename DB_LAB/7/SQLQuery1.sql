USE zurat_petcare;

CREATE TABLE employee (
    id INT IDENTITY (1, 1) PRIMARY KEY,
    NAME NVARCHAR (100) NOT NULL,
    address NVARCHAR (255),
    salary DECIMAL(10, 2)
);

CREATE TABLE employeeLog (
    logid INT IDENTITY (1, 1) PRIMARY KEY,
    empid INT NOT NULL,
    logdate DATETIME DEFAULT GETDATE (),
    logmsg NVARCHAR (MAX),
    CONSTRAINT FK_employeeLog_employee FOREIGN KEY (empid) REFERENCES employee (id)
);

