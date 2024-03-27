#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "bst.h"
#include "rb.h"

using namespace std;

int main()
{
    ifstream file1("testBad.csv");
    if(!file1.is_open())
    {
        cout << "Something Wrong Happen File Can not open Try again later"<<endl;
    }
    else
    {
        cout << "testBad.csv file is Opened Successfully Lets Play with this"<<endl;
        vector<int> tb;
        string line1;
        //getline(file1,line1); we need the first line 
        while(getline(file1,line1))
		{
			istringstream iss(line1);
			string data;
			getline(iss, data);
			tb.push_back(stoi(data));
		}
        cout << endl;
        cout << "Raw(meal) Data's From the file"<<endl;
        for(int i=0; i<tb.size(); i++)
		{
			cout << tb[i] << " ";	
		}
        cout << endl;
        cout<< "Binary Search Tree:" << endl;
        bst b1;
        cout << "A tree is ready for insertion:"<<endl;
        cout << "After Inserting out datas into our brandnew Binary tree: " << endl;
        for(int i=0; i<tb.size(); i++)
        {
            b1.InsertItem(tb[i]);
            //cout << "Item inserted Successfully: " << tb[i] << endl;
        }

        b1.Print();
        cout << endl;
        cout << "DEpth of tree:";
        b1.pdepth();
        cout << endl;
        cout << "Minimum of Tree: ";
        b1.Ptreemin();
        cout << "Maximum of tree:" ;
        b1.ptreemax();
        cout << endl;

        RedBlackTree rb1;
        cout << "REd Black Tree INsertion:"<<endl;
        for(int i=0; i<tb.size(); i++)
        {
            rb1.insert(tb[i]);
        } 
        cout << "Insertion Successful" <<endl;

        rb1.printInOrderTraversal();
        cout << endl;
        cout << "Cheacking the depth of RB Tree:";
        int a = rb1.depth();
        cout << a << endl;
        cout << endl;

        cout << "time for test my deletion skill haha"<< endl;

        
    ifstream filed("deleteNodes.csv");
    if(!filed.is_open())
    {
        cout << "Something Wrong Happen File Can not open Try again later"<<endl;
    }
    else
    {
        cout << "deleteNodes.csv file is Opened Successfully Lets Play with this"<<endl;
        vector<int> td;
        string line1;
        //getline(file1,line1); we need the first line 
        while(getline(filed,line1))
		{
			istringstream iss(line1);
			string data;
			getline(iss, data);
			td.push_back(stoi(data));
		}
        cout << endl;
        cout << "Raw(meal) Data's From the deletefile file"<<endl;
        for(int i=0; i<td.size(); i++)
		{
			cout << td[i] << " ";	
		}
        cout << endl;
        for(int i=0; i<td.size(); i++)
        {
            b1.DeleteItem(td[i]);
            rb1.remove(td[i]);
        }
    }

    cout << endl;
    cout << "After deleting them from  my bst tree look like this:" << endl;
    b1.Print();
    cout << endl;
    cout << "DEpth of my tree after deletion ";
    b1.pdepth();
    cout << endl;
    cout << "After deleting them from RB look like this: " << endl;
    rb1.printInOrderTraversal();
    cout<<endl;
    int b = rb1.depth();
    cout << "After deletion my depth would be: "<<b<<endl;
    
    }

    cout << endl << endl << endl;

     ifstream file2("testrandom.csv");
    if(!file2.is_open())
    {
        cout << "Something Wrong Happen File Can not open Try again later"<<endl;
    }
    else
    {
        cout << "testrandom.csv file is Opened Successfully Lets Play with this"<<endl;
        vector<int> tr;
        string line1;
        //getline(file1,line1); we need the first line 
        while(getline(file2,line1))
		{
			istringstream iss(line1);
			string data;
			getline(iss, data);
			tr.push_back(stoi(data));
		}
        cout << endl;
        cout << "Raw(meal) Data's From the file"<<endl;
        for(int i=0; i<tr.size(); i++)
		{
			cout << tr[i] << " ";	
		}
        cout << endl;

        bst b2;
        cout << "A tree is ready for insertion:"<<endl;
        cout << "After Inserting out datas into our brandnew Binary tree: " << endl;
        for(int i=0; i<tr.size(); i++)
        {
            b2.InsertItem(tr[i]);
            //cout << "Item inserted Successfully: " << tb[i] << endl;
        }

        b2.Print();
        cout << endl;
        cout << "Minimum of Tree: ";
        b2.Ptreemin();
        cout << "Maximum of tree:" ;
        b2.ptreemax();
        cout << endl;
        cout << "DEpth of tree:";
        b2.pdepth();
        cout << endl;

        RedBlackTree rb2;
        cout << "REd Black Tree INsertion:"<<endl;
        for(int i=0; i<tr.size(); i++)
        {
            rb2.insert(tr[i]);
        } 
        cout << "Insertion Successful" <<endl;

        rb2.printInOrderTraversal();
        cout << endl;
        cout << "Cheacking the depth of RB Tree:";
        int c = rb2.depth();
        cout << c << endl;
        cout << endl;



        ifstream filed("deleteNodes.csv");
    if(!filed.is_open())
    {
        cout << "Something Wrong Happen File Can not open Try again later"<<endl;
    }
    else
    {
        cout << "deleteNodes.csv file is Opened Successfully Lets Play with this"<<endl;
        vector<int> td;
        string line1;
        //getline(file1,line1); we need the first line 
        while(getline(filed,line1))
		{
			istringstream iss(line1);
			string data;
			getline(iss, data);
			td.push_back(stoi(data));
		}
        cout << endl;
        cout << "Raw(meal) Data's From the deletefile file"<<endl;
        for(int i=0; i<td.size(); i++)
		{
			cout << td[i] << " ";	
		}
        cout << endl;
        for(int i=0; i<td.size(); i++)
        {
            b2.DeleteItem(td[i]);
            rb2.remove(td[i]);
        }
    }

    cout << endl;
    cout << "After deleting them my bst tree look like this:" << endl;
    b2.Print();
    cout << endl;
     cout << "DEpth of my tree after deletion ";
    b2.pdepth();
    cout << endl;

    cout << "After deleting them from RB look like this: " << endl;
    rb2.printInOrderTraversal();
    cout<<endl;
    int d = rb2.depth();
    cout << "After deletion my depth would be: "<<d<<endl;


    }
}