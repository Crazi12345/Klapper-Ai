insert into trained_data(id,data,label) select * from untrained_data fetch first 1 row only;
insert into trained_data(id,data,label) select * from untrained_data;
insert into untrained_data(id,data,label)
                                       select id,data,label from trained_data;



select * from untrained_data;

DELETE from trained_data where id in ( select id from trained_data fetch first 1 row only );