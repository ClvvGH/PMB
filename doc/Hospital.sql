CREATE SCHEMA `hospital` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci ;
use hospital;

create table doctor 
(
	DId int primary key auto_increment,
	name varchar(10),
    sex char(2) check(sex = '男' or sex = '女'),
    bornYear smallint check(bornYear >0 and bornYear <2017),
    department varchar(10),
    tel varchar(20),
    hireDate date,
    password varchar(20),
    position varchar(10),
    username varchar(20)
)engine = InnoDB default charset = utf8;

create table patient
(
	PId int primary key auto_increment,
    username varchar(20),
    name varchar(10),
    tel varchar(20),
    bornYear smallint check(bornYear >0 and bornYear <2017),
	password varchar(20),
    sex char(2) check(sex = '男' or sex = '女')
)engine = InnoDB default charset = utf8;

create table treatment
(
	DId int,
    PId int,
    diseaseName varchar(20),
    description text,
    diagnose text,
    advice text,
    prescription text,
    date datetime,
    foreign key (DId) references doctor(DId) ON DELETE CASCADE ON UPDATE CASCADE ,
    foreign key (PId) references patient(PId) ON DELETE CASCADE ON UPDATE CASCADE 
)engine = InnoDB default charset = utf8;

create table variable
(
	VId int primary key auto_increment,
    name varchar(10),
    unit varchar(10)
)engine = InnoDB default charset = utf8;

create table examination
(
	DId int,
    PId int,
    VId int,
    value double,
    date datetime,
    foreign key (DId) references doctor(DId) ON DELETE CASCADE ON UPDATE CASCADE ,
	foreign key (PId) references patient(PId) ON DELETE CASCADE ON UPDATE CASCADE ,
    foreign key (VId) references variable(VId) ON DELETE CASCADE ON UPDATE CASCADE 
)engine = InnoDB default charset = utf8;


create table clientAction
(
	CId int primary key auto_increment,
    ip varchar(20),
    action varchar(100),
    date datetime
)engine = InnoDB default charset = utf8;
