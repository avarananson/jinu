#include <fstream>
#include <iostream>
using namespace std;
int main()
{


    string auth = "@author :";
    string version= "@version:";
    string date = "Date:";
    string Bug  = "BUG ID";
    string info = "@info ";
    std::ifstream file("test.txt");
    if (file.is_open()) {
    std::string line ;
    std::getline(file, line);
    while (1) {
        if(line.find(auth) != string::npos)
        {
            string data = line.substr(line.find(auth) + auth.length(), line.find('(') - (line.find(auth) + auth.length()));
            cout<<data<<endl;
            if(line.find(Bug) != string::npos)
            {
               string data = line.substr(line.find(Bug) + Bug.length(),line.find(")")-(line.find(Bug) + Bug.length()));
                cout<<data<<endl;

            }
            std::getline(file, line);
            if(line.find(version) != string::npos)
            {
               string data = line.substr(line.find(version) + version.length(), line.find(date) - (line.find(version) + version.length()));
               cout<<data<<endl;


            }
            if(line.find(date) != string::npos)
            {

              string data = line.substr(line.find(date)+date.length());
               cout<<data<<endl;
            }
            if(!std::getline(file, line))
                break;
            else if(line.find(auth) == string::npos)
            {
               if(line.find(info) != string::npos)
            {
            if(line.find(Bug) != string::npos)
            {
              string data = line.substr(line.find(Bug) + Bug.length(),line.find(")")-(line.find(Bug) + Bug.length()));
               cout<<data<<endl;
            }

            }
              if(!std::getline(file, line))
                break;
            }



        }
        else
        if(!std::getline(file, line))
            break;



    }

}
}
