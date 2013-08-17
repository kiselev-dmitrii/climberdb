CREATE TABLE Client (
	"ID"			Integer			PRIMARY KEY AUTOINCREMENT,
	"Name"			Varchar(30),
	"Surname"		Varchar(30),
	"Mobile"		Varchar(20),
	"Address"		Varchar(60),
	"Discount"		Real			DEFAULT(0),
	"CountBuy"		Integer			DEFAULT(0),
	"CountReturns"	Integer			DEFAULT(0),
	"Rating"		Real			DEFAULT(0)
);

CREATE TABLE Product (
	"ID"				Integer			PRIMARY KEY AUTOINCREMENT,
	"ConsignmentID"		Integer			NOT NULL,
	"Size"				Varchar(10),
	"Barcode"			Varchar(20)		DEFAULT(NULL),
	"IsSold"			Boolean			DEFAULT(0),
	"SellingCost"		Integer,
	"DeliveryDate"		DateTime,
	"SaleDate"			DateTime		DEFAULT(NULL),
	"LastReturnDate"	DateTime		DEFAULT(NULL),
	"CountBuy"			Integer			DEFAULT(0),
	"CountReturns"		Integer			DEFAULT(0),
	"ClientID"			Integer			DEFAULT(NULL),

	CONSTRAINT	"Fk_ClientID"		FOREIGN KEY ("ClientID") REFERENCES Client("ID")
);

CREATE TABLE Country (
	"ID"		Integer			PRIMARY KEY AUTOINCREMENT,
	"Name"		Varchar(50)		NOT NULL 	UNIQUE
);

CREATE TABLE Type (
	"ID"		Integer			PRIMARY KEY AUTOINCREMENT,
	"Name"		Varchar(40)		NOT NULL	UNIQUE
);

CREATE TABLE Color (
	"ID"		Integer			PRIMARY KEY AUTOINCREMENT,
	"Name"		Varchar(40)		NOT NULL	UNIQUE
);

CREATE TABLE Consignment (
	"ID"		Integer			PRIMARY KEY AUTOINCREMENT,
	"Name"		Varchar(30) 	NOT NULL,
	"Model"		Varchar(30)		NOT NULL,
	"ColorID"	Integer			DEFAULT(NULL),
	"TypeID"	Integer,
	"Gender"	Varchar(10)		DEFAULT(NULL),
	"Comment"	Varchar(40)		DEFAULT(NULL),
	"Cost" 		Integer,
	"CountryID"	Integer			DEFAULT(NULL),

	CONSTRAINT	"Fk_ColorID"		FOREIGN KEY ("ColorID") REFERENCES Color("ID"),
	CONSTRAINT	"Fk_TypeID"			FOREIGN KEY ("TypeID") REFERENCES Type("ID"),
	CONSTRAINT	"Fk_CountryID"		FOREIGN KEY ("CountryID") REFERENCES Country("ID")
);

CREATE INDEX "idx1" ON Consignment("Name");
CREATE INDEX "idx2" ON Consignment("Model");
CREATE INDEX "idx3" ON Product("Barcode");
CREATE INDEX "idx4" ON Product("ConsignmentID");
CREATE INDEX "idx5" ON Product("Size");
CREATE INDEX "idx6" ON Product("DeliveryDate");
CREATE INDEX "idx7" ON Product("SaleDate");
CREATE INDEX "idx8" ON Product("ClientID");
CREATE INDEX "idx9" ON Client("Mobile");