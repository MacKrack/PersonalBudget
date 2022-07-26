# PersonalBudget

Personal Budget is an app made in C++ technology, following the OOP principles. You can create single accounts for many Users, who can trace their incomes and expenses by registering them in this app. At any moment they can display a balance of spending in a few variants: for the current month, the previous month and for User selected period.

Watch and control where your money goes.

How to compile:
g++ -o main main.cpp AccountMovement.cpp AccountMovementMenager.cpp AdditionalMethods.cpp DateMenager.cpp FileRegisteringAccountMovements.cpp FileWithUsers.cpp PersonalBudget.cpp User.cpp UserMenager.cpp xmlFile.cpp Markup.cpp -liconv