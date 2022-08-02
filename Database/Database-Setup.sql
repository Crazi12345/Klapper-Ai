Create table untrained_data(
    id serial Primary Key,
    data integer[],
    label varchar(64)
);

Create table trained_data(
    id serial Primary Key,
    data integer[],
    label varchar(64),
    outcome bool
);

Create table nodes(

    id varchar(64),
    weights decimal[]
);

create table bias(
    id varchar(64) PRIMARY KEY,
    weight decimal[]

);