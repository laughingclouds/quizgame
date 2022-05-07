-- Create the tables
CREATE TABLE IF NOT EXISTS "user" (
        "id"    INTEGER NOT NULL UNIQUE,
        "name"  TEXT DEFAULT 'No Name',
        "password"      TEXT DEFAULT '',
        "score" REAL DEFAULT 0,
        PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "option" (
        "id"    INTEGER NOT NULL UNIQUE,
        "text"  TEXT DEFAULT 'None' UNIQUE,
        PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "category" (
        "id"    INTEGER NOT NULL UNIQUE,
        "name"  TEXT DEFAULT 'Not Defined',
        PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "question" (
        "id"    INTEGER NOT NULL UNIQUE,
        "categoryId"    INTEGER NOT NULL DEFAULT 0,
        "answerId"      INTEGER NOT NULL DEFAULT 0,
        "option2Id"     INTEGER NOT NULL DEFAULT 0,
        "option3Id"     INTEGER NOT NULL DEFAULT 0,
        "option4Id"     INTEGER NOT NULL DEFAULT 0,
        "text"  TEXT NOT NULL DEFAULT 'Question Not Found',
        FOREIGN KEY("option2Id") REFERENCES "option"("id"),
        FOREIGN KEY("option3Id") REFERENCES "option"("id"),
        FOREIGN KEY("categoryId") REFERENCES "category"("id"),
        FOREIGN KEY("answerId") REFERENCES "option"("id"),
        FOREIGN KEY("option4Id") REFERENCES "option"("id"),
        PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "solved" (
        "question_id"   INTEGER NOT NULL DEFAULT 0,
        "user_id"       INTEGER NOT NULL DEFAULT 0,
        FOREIGN KEY("question_id") REFERENCES "question"("id"),
        FOREIGN KEY("user_id") REFERENCES "user"("id")
);

-- Insert basic data into the tables
INSERT INTO user (name, password, score) VALUES ("No Name", " ", 0);
INSERT INTO option VALUES (0, "Not Found"), (1, "None");
INSERT INTO category VALUES (0, "Misc");
INSERT INTO question VALUES (0, 0, 0, 0, 0, 0, "Question Not Found");