#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
protected:
    int id;
    string title;
    bool isAvailable;
public:
    Item(int i , string t)
    {
        id = i;
        title = t;
        isAvailable = true;
    }

    int getid()
    {
        return id;
    }

    string gettitle()
    {
        return title;
    }

    bool getisAvailable()
    {
        return isAvailable;
    }

    void setid(int i)
    {
        id =i;
    }

    void settitle(string t)
    {
        title = t;
    }

    void setisAvailable(bool is)
    {
        isAvailable = is;
    }

    virtual void displayInfo()= 0;

};

class Book:public Item
{
private:
    string author;
    string genre;
public:
    Book(int i , string t  , string a , string g):Item(i , t)
    {
        author = a;
        genre = g;
    }

    void displayInfo()override
    {
        cout <<"ID: "<<id<<endl
        <<"title: "<<title<<endl
        <<"author: "<<author<<endl
        <<"genre: "<<genre<<endl;
    }
};

class Magazine:public Item
{
private:
    int issueNumber;
public:
    Magazine(int i , string t  , int iss):Item(i , t )
    {
        issueNumber = iss;
    }

    void displayInfo()override
    {
        cout <<"ID: "<<id<<endl
        <<"title: "<<title<<endl
        <<"issueNumber: "<<issueNumber<<endl;
    }
};

class DvD:public Item
{
private:
    string director;
    double duration;
public:
    DvD(int i , string t  , string d , double du):Item(i , t )
    {
        director = d;
        duration = du;
    }

    void displayInfo()override
    {
        cout << "ID: " << id << endl
        << "title: " << title << endl
        << "director: " << director << endl
        << "duration: " << duration << endl;
    }
};

int main()
{
   vector <Book> Books;
   vector <Magazine> Magazines;
   vector <DvD> DvDs;

   int choice;

   do
   {
     cout <<"========== Library Management System =========="<<endl;
     cout <<"1. Add Book" <<endl;
     cout <<"2. Add Magazine" <<endl;
     cout <<"3. Add DVD"<<endl;
     cout <<"4. Show All Items"<<endl;
     cout <<"5. Borrow Item"<<endl;
     cout <<"6. Return Item"<<endl;
     cout <<"7. Search by ID"<<endl;
     cout <<"8. Exit"<<endl;

     cout <<"Enter your choice: "<<endl;
     cin >> choice;

     if(choice == 1)
     {
         int id;
         string title, author, genre ;
         cout <<"enter iD: title: author: genre: "<<endl;
         cin >> id >> title >> author >> genre ;

         Books.push_back(Book(id , title  , author , genre ));
     }

     else if(choice == 2)
     {
         int id;
         string title;
         int issueNumber;

         cout <<"enter iD: title: issueNumber:"<<endl;
         cin >> id >> title >> issueNumber;

         Magazines.push_back(Magazine(id , title  , issueNumber));
     }

     else if(choice == 3)
     {
         int id;
         string title , director;
         double duration;

         cout <<"enter iD: title: director: duration:"<<endl;
         cin >> id >> title >> director >> duration;


         DvDs.push_back(DvD(id , title , director , duration ));
     }

     else if(choice == 4)
     {
         for(int i = 0 ; i < Books.size() ; i++)
         {
             Books[i].displayInfo();
         }

         for(int i = 0 ; i < Magazines.size() ; i++)
         {
             Magazines[i].displayInfo();
         }

         for(int i = 0 ; i < DvDs.size() ; i++)
         {
             DvDs[i].displayInfo();
         }

     }

         else if(choice == 5)
         {
             int id;
             cout << "Enter ID: " << endl;
             cin >> id;

             bool found = false;

             for(int i = 0; i < Books.size(); i++)
              {
                  if(Books[i].getid() == id)
                   {
                      if(Books[i].getisAvailable())
                        {
                           Books[i].setisAvailable(false);
                           cout << "Book borrowed successfully." << endl;
                        }
                      else
                        {
                           cout << "Book is already borrowed." << endl;
                        }

                      found = true;
                   }
              }

             for(int i = 0; i < Magazines.size(); i++)
              {
                   if(Magazines[i].getid() == id)
                    {
                       if(Magazines[i].getisAvailable())
                         {
                               Magazines[i].setisAvailable(false);
                               cout << "Magazine borrowed successfully." << endl;
                         }
                       else
                        {
                              cout << "Magazine is already borrowed." << endl;
                        }

                       found = true;
                    }
             }

              for(int i = 0; i < DvDs.size(); i++)
               {
                   if(DvDs[i].getid() == id)
                   {
                      if(DvDs[i].getisAvailable())
                       {
                           DvDs[i].setisAvailable(false);
                           cout << "DVD borrowed successfully." << endl;
                       }
                      else
                       {
                            cout << "DVD is already borrowed." << endl;
                       }

                      found = true;
                   }
               }

              if(!found)
               {
                    cout << "Item not found." << endl;
               }
         }
        else if(choice == 6)
        {
            int id;
            cout << "Enter ID: " << endl;
            cin >> id;

            bool found = false;

        for(int i = 0; i < Books.size(); i++)
        {
              if(Books[i].getid() == id)
               {
                     Books[i].setisAvailable(true);
                     found = true;
               }
        }

        for(int i = 0; i < Magazines.size(); i++)
        {
              if(Magazines[i].getid() == id)
               {
                    Magazines[i].setisAvailable(true);
                    found = true;
               }
        }

        for(int i = 0; i < DvDs.size(); i++)
        {
            if(DvDs[i].getid() == id)
             {
                 DvDs[i].setisAvailable(true);
                 found = true;
             }
        }

       if(!found)
         {
            cout << "Item not found" << endl;
         }
       }

     else if(choice == 7)
     {
         int id;
         cout <<"enter iD: "<<endl;
         cin >>id;

         bool found = false;

         for(int i = 0 ; i < Books.size() ; i++)
         {
             if(Books[i].getid() == id)
             {
                 Books[i].displayInfo();
                 found = true;
             }
         }

         for(int i = 0 ; i < Magazines.size() ; i++)
         {
             if(Magazines[i].getid() == id)
             {
                 Magazines[i].displayInfo();
                 found = true;
             }
         }

         for(int i = 0 ; i < DvDs.size() ; i++)
         {
             if(DvDs[i].getid() == id)
             {
                 DvDs[i].displayInfo();
                 found = true;
             }
         }

         if(!found)
         cout <<"Item not found"<<endl;
     }

   }while(choice != 8);


    return 0;
}
