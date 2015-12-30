_config["sql"] = {};
_config["sql"]["users1"] = "";


def db_init(inp):
	if('d' in inp):
		for i in ["users"]:
			print _sql.q("drop table if exists "+i);
	if('i' in inp):
		print _sql.q("create table if not exists users (id int NOT NULL AUTO_INCREMENT, phone varchar(100), password varchar(100), email varchar(100),  name varchar(100), address varchar(500), type varchar(3), create_time int, update_time int, last_login int, last_ip varchar(20), conf varchar(1), profilepic varchar(100), profilepic_small varchar(200), PRIMARY KEY ( id) ) ");

