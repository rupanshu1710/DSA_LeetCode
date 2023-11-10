# Write your MySQL query statement below
SELECT date_id, make_name, COUNT(Distinct(lead_id)) as unique_leads, COUNT(Distinct(partner_id))as unique_partners from DailySales Group By date_id, make_name;