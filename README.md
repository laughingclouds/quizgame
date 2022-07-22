# quizgame

A Quiz Game written in golang.

> Mini-Project made for the Summer Training program of my Uni

## History

1. [Working example using ncurses library and C++](https://github.com/laughingclouds/quizgame/tree/917462b)
2. [Complete project using drogon framework](https://github.com/laughingclouds/quizgame/tree/def7792)
3. Now. Rewrite in golang


## Acknowledgement

As a novice in Go programming and Gin framework (and web development in general) I frequently referred to the [go-banking-api](https://github.com/Devansh3712/go-banking-api) project by [Devansh](https://github.com/Devansh3712). Thanks for being awesome!


## Database

We're going to need a postgres database to start. I've already included an SQL script to create the tables and add sample data into them.

- cd into project directory
- run the below script for user `postgres` who owns a database `quizgame`

```bash
psql -U postgres -d quizgame -a -f backend/scripts/database.sql
```

Quiz game uses the following environment variables to connect to a database.

| Environment Variables |
| --------------------- |
| QZ_HOSTNAME | 
| QZ_USERNAME |
| QZ_PASSWORD |
| QZ_DBNAME |

```bash
export QZ_HOSTNAME="localhost"
export QZ_USERNAME="postgres"
export QZ_PASSWORD="PASSWORD"
export QZ_DBNAME="quizgame"
```