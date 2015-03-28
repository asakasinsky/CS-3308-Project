CREATE TABLE IF NOT EXISTS "Routes" (
"ID" INTEGER PRIMARY KEY,
"Name" char
)
;

CREATE TABLE IF NOT EXISTS "Coordinates" (
"ID" INTEGER PRIMARY KEY,
"RouteID" int REFERENCES "Routes"("ID") ON DELETE CASCADE ON UPDATE CASCADE
)
;

CREATE TABLE IF NOT EXISTS "Times" (
"ID" INTEGER PRIMARY KEY,
"CoordinateID" int REFERENCES "Coordinates"("ID") ON DELETE CASCADE ON UPDATE CASCADE
)
;
