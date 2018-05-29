-- vim: sw=4 ts=4 :
-- schema for the local database

BEGIN;

CREATE TABLE IF NOT EXISTS times
(
	project INTEGER NOT NULL,
	starting DATETIME DEFAULT (datetime('now', 'localtime')),
	ending DATETIME DEFAULT NULL,
	comment TEXT
);

CREATE UNIQUE INDEX IF NOT EXISTS times1 ON times (project,starting);
CREATE INDEX IF NOT EXISTS times2 ON times (project);

CREATE TABLE IF NOT EXISTS projects 
(
	id INTEGER PRIMARY KEY,
	name TEXT UNIQUE NOT NULL
);

COMMIT;
