from msl import *
from msl.help import *
from msl.sql import *
from msl.mtime import *;

execfile("includes/password.py");

_project = "sabi";

if(_server == 'gcl'):
	HOST = 'http://poorvi.cse.iitd.ac.in/~cs1120233/'+_project+'/';
	ROOT = '/home/btech/cs1120233/private_html/'+_project+'/';
	db_data = {'host': 'poorvi.cse.iitd.ac.in', 'user': 'mohit', 'pass': 'mohitsaini', 'db': 'mohit'};
	_msladd = 'msl/'
	db_data["qs_host"] = "10.208.20.185";
	db_data["qs_host"] = "10.208.20.186";

elif(_server == 'csc'):
	HOST = 'http://privateweb.iitd.ac.in/~cs1120233/'+_project+'/';
#	ROOT = '/home/btech/cs1120233/private_html/'+_project+'/';
	ROOT = '/home/cse/btech/cs1120233/private_html/'+_project+'/';
	db_data = {'host': 'poorvi.cse.iitd.ac.in', 'user': 'mohit', 'pass': 'mohitsaini', 'db': 'mohit'};
	_msladd = '~/.local/lib/python2.7/site-packages/msl/';
	db_data["qs_host"] = "10.208.20.9";


elif(_server == "aws"):
	HOST = 'http://54.149.49.212/'+_project+'/';
	ROOT = '/var/www/html/'+_project+'/';
	db_data = {'host': 'localhost', 'user': 'root', 'pass': 'mohit', 'db': ''+_project+''};
	_msladd = '/usr/lib/python2.7/msl/';

elif(_server == "aws_'+_project+'"):
	HOST = 'http://52.8.204.132/';
	HOST = 'https://www.'+_project+'box.in/';
	ROOT = '/var/www/html/';
	db_data = {'host': 'localhost', 'user': 'root', 'pass': 'mohit', 'db': ''+_project+''};
	_msladd = '/usr/lib/python2.7/msl/';


elif(_server == "solnki"):
	HOST = 'http://localhost/'+_project+'/';
	ROOT = '/var/www/html/'+_project+'/';
	db_data = {'host': '10.208.20.8', 'user': 'mohit', 'pass': 'mohitsaini', 'db': 'mohit'};
	_msladd = '/usr/lib/python2.7/msl/';

elif(_server == "mohit"):
	HOST = 'http://localhost/'+_project+'/';
	ROOT = '/var/www/'+_project+'/';
	db_data = {'host': '10.208.20.8', 'user': 'mohit', 'pass': 'mohitsaini', 'db': 'mohit'};
	db_data = {'host': 'localhost', 'user': 'root', 'pass': 'mohitsaini', 'db': 'sabi'};
	_msladd = '/usr/lib/python2.7/msl/';


db_data["qs_port"] = 1136;

CDN = HOST+'photo/'
BASE = HOST+'index.php/'
_mslib = ROOT+"mslib/";
_includes = [];

