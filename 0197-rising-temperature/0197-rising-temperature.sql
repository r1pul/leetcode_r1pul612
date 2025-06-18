SELECT w1.id FROM WEATHER w1
join WEATHER w2
on datediff(w1.recordDate,w2.recordDate)=1
where w1.temperature > w2.temperature;

