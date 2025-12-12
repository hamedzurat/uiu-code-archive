USE zurat_petcare;

DROP TABLE Nominee;
DROP TABLE Account;

CREATE TABLE Account (
    AccNo INT PRIMARY KEY,
    Name VARCHAR(20) NOT NULL,
    Balance INT NOT NULL
);

CREATE TABLE Nominee (
    ID INT PRIMARY KEY,
    Name VARCHAR(20) NOT NULL,
    Relation VARCHAR(20) NOT NULL,
    AccID INT NOT NULL,
    FOREIGN KEY (AccID) REFERENCES Account(AccNo) ON DELETE CASCADE
);

INSERT INTO Account (AccNo, Name, Balance) VALUES
(1, 'John', 100),
(2, 'Jermy', 200),
(3, 'Kim', 100),
(4, 'Jemes', 400),
(5, 'Bob', 600),
(6, 'Karl', 300);

INSERT INTO Nominee (ID, Name, Relation, AccID) VALUES
(1, 'AA', 'son', 1),
(2, 'BB', 'daughter', 1),
(3, 'CC', 'son', 2),
(4, 'DD', 'wife', 3),
(5, 'EE', 'wife', 4),
(6, 'FF', 'wife', 5),
(7, 'ZZ', 'Dad', 6);

SELECT 
    Account.AccNo,
    Account.Name,
    Account.Balance,
    Nominee.ID,
    Nominee.Name,
    Nominee.Relation
FROM Account
JOIN Nominee
    ON Account.AccNo = Nominee.AccID;

DELETE FROM Account WHERE AccNo = 1;

SELECT 
    Account.AccNo,
    Account.Name,
    Account.Balance,
    Nominee.ID,
    Nominee.Name,
    Nominee.Relation
FROM Account
JOIN Nominee
    ON Account.AccNo = Nominee.AccID;
