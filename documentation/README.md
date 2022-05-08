A question and answer type of document which will tell you how to answer the externals questions. I will link to resources you will need to read to be able to answer these questions.

> I won't gaurantee that they will ask you these questions only.

How to read this document?
Go from top to bottom, read the questions and their answers.
After that read through the links in the pre-requisite knowledge section.

# Title 

> What is the title of your project?

A web-based quiz game made using the drogon framework which works on the MVC architecture.

> Tell me about your project.

The title of my project is, "A web-based quiz game made using the drogon framework which works on the MVC architecture."

It is a *design type* project and its outcome is a *product*. Which is, a quiz-game application.


## Basic Questions

> What do you mean by "web-based"?

It means that the application will have a web front-end.

## Phase 1 questions
> What problems does your project solve?

- Our project aims to provide a learning and entertainment platform to people
- It helped us understand the process of building a product and the thought process behind it.
- We also learned teamwork and project management skills
- Lastly we learned new technologies that helped us in the communication and project building process.

> What tools did you use for project management?

- We used a feature in github called "projects" to manage all the tasks. It divides different tasks into lists, such as a "todo" list, an "issues" list, a "pending pull requests" list etc.
- We also used a version control system called git to manage the source code of the project.
- The source code is hosted on github.

> What benefit does it bring to society?

- The product made from this project can be used by students to practise their knowledge in various subjects.
- It can be used by institutions to conduct examinations and keep track of the scores of the examinees.
- It can also be used as a quiz for entertainment depending what category a user chooses.

## Phase 3 questions

> What features does your project have?
> NOTE: First mention their names, and then their information

This project has the following main features:
- **Login**: A session will be cerated, allowing the user to save their progress in the database.
- **Logout**: They will also be able to "logout" to allow other users to login.
- **Leaderboard**: will show users with the top scores.
- **Add New User**: will allow be new users to create their own accounts.
- **Start Game**: will start the quiz. Only users who have logged in can start the quiz.
 
> What different design solutions did your team come up with?

We created two design solutions for the database:
1. In the first design, one whole table would be dedicated to every user, and it also did not have an option to store the password.
2. In the second design, everything would be simpler and there was also the option to store the user password.

We also thought of two approaches for the whole front-end of the project:
1. In the first approach, we would create a terminal-based quiz-game which would use the ncurses library.
2. In the second approach, we would use the web-browser for the application front-end.

We chose the second approach as the team believed that working with HTML and CSS was easier.


## Questions About Drogon and MVC

> What is drogon?

**Drogon** is an HTTP application framework which can be used to easily build various types of web application server programs using C++

> What is MVC?

The **Model-View-Controller (MVC)** is an architectural pattern that separates an application into three main logical components: the **model**, the **view**, and the **controller**. Each of these components are built to handle specific development aspects of an application.

> How is file handling used in this project?
> What is the use of DBMS in this project?

- We are using an SQLite database instead of file handling to store data. This database is stored locally. And we use the ORM provided by the drogon framework to access the database.
- We use a database to store the different categories of the quiz, and all the questions and their options. We store user information such as username and password, and also what questions were already solved by a user.
- The database has five tables in total, namely:
	1. **user**
	2. **option**
	3. **category**
	4. **question**
	5. **solved**






It will be a good idea to have a basic understanding of them.


We are accessing the database through dockers ORM.

Our group was divided into two teams 

I was part of the front-end team.

My responsibility was to:

I was part of the back-end team.

## Pre-requisite knowledge

These are the important keywords you can be asked questions about:

- Version Control System
	- [What is a VCS? [gfg]](https://www.geeksforgeeks.org/version-control-systems/)
	- [What is a VCS? [git-scm.com]](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)
- MVC architecture
	- [tutorialspoint](https://www.tutorialspoint.com/mvc_framework/mvc_framework_introduction.htm)
	- [MDN](https://developer.mozilla.org/en-US/docs/Glossary/MVC)
- ORM
	- [What is orm?](https://stackoverflow.com/questions/1279613/what-is-an-orm-how-does-it-work-and-how-should-i-use-one)
	- [How to query database using drogons ORM](https://drogon.docsforge.com/master/database-general/database-orm/)
- [drogons CSP](https://drogon.docsforge.com/master/view/#drogons-csp)
- [drogon framework](https://drogon.docsforge.com/master/overview/)