USE MidExamFall2025;

SELECT
    *
FROM
    APPOINTMENTS;

SELECT
    *
FROM
    DOCTORS;

SELECT
    *
FROM
    PATIENTS;

-- 1)
SELECT DISTINCT
    specialization
FROM
    DOCTORS
ORDER BY
    specialization;

-- 2)
SELECT
    d.doctor_name,
    d.specialization,
    Sum(a.fees_paid) AS total_revenue
FROM
    APPOINTMENTS a
    JOIN DOCTORS d ON d.doctor_id = a.doctor_id
GROUP BY
    doctor_name,
    specialization
ORDER BY
    total_revenue DESC;

-- 3)
SELECT
    p.patient_name,
    Count(A.appointment_id) AS appointment_count
FROM
    APPOINTMENTS a
    RIGHT JOIN PATIENTS p ON p.patient_id = a.patient_id
GROUP BY
    patient_name
ORDER BY
    appointment_count DESC;

