DROP DATABASE IF EXISTS BookDB
GO

CREATE DATABASE BookDB
GO

USE BookDB

CREATE TABLE State
(
	StateId NVARCHAR(256) PRIMARY KEY,
	StateName NVARCHAR(MAX)
)
GO

CREATE TABLE TypePlace
(
	TypePlaceId NVARCHAR(256) PRIMARY KEY,
	TypeName NVARCHAR(MAX)
)
GO

CREATE TABLE Place
(
	PlaceId NVARCHAR(256) PRIMARY KEY,
	Name NVARCHAR(MAX),
	StateId INT FOREIGN KEY REFERENCES State(StateID),
	TypePlaceId INT FOREIGN KEY REFERENCES TypePlace(TypePlaceId)
)
GO

CREATE TABLE Book
(
	BookId INT IDENTITY(1,1) PRIMARY KEY,
	Title NVARCHAR(MAX),
	FirstEditionDate Date
)
GO

CREATE TABLE Author
(
	AuthorId INT IDENTITY(1,1) PRIMARY KEY,
	FirstName NVARCHAR(MAX), 
	SecondName NVARCHAR(MAX),
	BirthDate DATE,
	DeathDate DATE,
	BrithDatePlaceId INT FOREIGN KEY REFERENCES Place(PlaceId),
	DeathDatePlaceId INT FOREIGN KEY REFERENCES Place(PlaceId),
)
GO

CREATE TABLE AuthorBook
(
	BookId INT FOREIGN KEY REFERENCES Book(BookId),
	AuthorId INT FOREIGN KEY REFERENCES Author(AuthorId),
	PRIMARY KEY(BookId, AuthorId)
)
GO

SET IDENTITY_INSERT State ON
INSERT INTO State(StateId, StateName)
	VALUES('SouthAfrica', 'South Africa'),
	      ('England', 'England'),
		  ('USA', 'U.S.A')
SET IDENTITY_INSERT State OFF

SET IDENTITY_INSERT TypePlace ON
INSERT INTO TypePlace(TypePlaceId, TypeName)
	VALUES('cityType', 'City')
SET IDENTITY_INSERT TypePlace OFF

SET IDENTITY_INSERT Place ON
INSERT INTO Place(PlaceId, Name, StateId, TypePlaceId)  
	VALUES('Bloemfontein', 'Bloemfontein', 1, 1),
		  ('Bournemouth', 'Bournemouth', 2, 1) ,
		  ('Lowell', 'Lowell', 3, 1),
		  ('StPetersburg', 'St. Petersburg', 3, 1),
		  ('Minneapolis', 'Minneapolis', 3, 1),
		  ('SouthBerg', 'South Berg', 3, 1)
SET IDENTITY_INSERT Place OFF

SET IDENTITY_INSERT Author ON
INSERT INTO Author(AuthorId, FirstName, SecondName, BirthDate, DeathDate, BrithDatePlaceId, DeathDatePlaceId)
	VALUES(1, 'John Ronald Reuel', 'Tolkien', '1892-1-3', '1973-9-2', 1, 2),
	      (2, 'Jack', 'Kerouac', '1922-3-12', '1969-8-21', 3, 4),
		  (3, 'Robert Maynard', 'Pirsing', '1928-9-6', '2017-4-24', 5, 6)
SET IDENTITY_INSERT Author OFF

SET IDENTITY_INSERT Book ON
INSERT INTO Book(BookId, Title)
	VALUES(1, 'The Lord of the Rings'),
	      (2, 'The Hobbit'),
		  (3, 'The Silmarillion'),
		  (4, 'On the road'),
		  (5, 'The Dharma Bums'),
		  (6, 'Zen and the Art of Motorcycle Maintenance')
SET IDENTITY_INSERT Book OFF

INSERT INTO AuthorBook(BookId, AuthorId)
	VALUES(1, 1),
		  (2, 1),
		  (3, 1),
		  (4, 2),
		  (5, 2),
		  (6, 3)