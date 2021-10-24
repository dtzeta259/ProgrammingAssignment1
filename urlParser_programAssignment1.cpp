/*
     C++ Program that will take in one argument in the form of a url of type string and will
     output the components of the url. Program will analyze the imput by each component and
     will display any error messages should one of the components be erroneous. The url
     consists of several different components: the Protocols, domain, port, file path, and
     parameters (which are optional)
 
    Created by David Teran (dxt180025)
 */
#include <iostream>
#include <string>
#include "version.cpp"

float version = 1.2;
using namespace std;

//Function Prototypes
void userPrompt(string url);
void parseURL(string url);

int main(){
    //Variables used in main
    string url;

    //Call for version
    displayVersion(version);

    //Call for user prompt funtion
    userPrompt(url);
    
    
    return 0;
}
//Function: userPrompt
//Type: void
//Parameters: string
//userPrompt function will take in the url of type string
//as the argument and will print out the prompt for the user
//to enter the url to parse.
void userPrompt(string url){
    
    //Prompt user to enter a url
    cout << "Please enter a URL to parse: \n";
    getline(cin, url);
    
    //Call for the parser function
    parseURL(url);
    
}

//Function: parseURL
//Type: void
//Parameters: string
//parseURL function will read in the url of type string
//and will separate the URL by its components by
//taking the substring of the URL. Once that is done,
//each component will be checked for errors. If there
//are no error, print out the components, else print
//out the error message.
void parseURL(string url){
    //Variables for this function
    string protocol;
    string domain;
    int port = 0;
    string pathFile;
    string html;
    string parameters;
    
    //For Error Message
    string error = "";
    
    //Standard url protocols
    string validProtos[] = {"http", "https", "ftp", "ftps"};
    
    //Standard url domains
    string validDomains[] = {"com", "net", "edu", "biz", "gov", "org"};
        
    //Get the substrings for the respective url components
    
    //Protocols
    protocol = url.substr(0, url.find("://"));
    //Domain
    string remains = url.substr(url.find("://") + 3);
    domain = remains.substr(0, remains.find(":"));
    //Port
    port = stoi(remains.substr(remains.find(":") + 1));
    //File Path
    string domremains = remains.substr(remains.find("/"));
    pathFile = domremains.substr(0, domremains.find("?"));
    //Parameters
    parameters = domremains.substr(domremains.find("?"));
    
    //Now, validate these componenrs before displaying them
        //Protocol validation
        for(int i = 0; i < 4; i++){
            if(protocol == validProtos[i]){

            }else if(i > 3){
                error = ("\nProtocol: " + protocol + " is not a valid protocol.");
            }
        }
    
        //Domain Validation
        string enddom = remains.substr(remains.find(":") - 3, 3);
        for(int j = 0; j < 6; j++){
            if(enddom == validDomains[j]){
                //cout << "Domain: " << domain << endl;
            }else if(j> 5){
                error = error + ("\nDomain: " + domain + " is not a valid domain.");
            }
        }
        //Port validation
        if(port < 0 || port > 65535){
            error = error + ("\nPort: " + to_string(port) + " is not a valid port number.");
        }else {
            //cout << "Port: " << port << endl;
        }
        //Path File Validation
        if(pathFile.find("html") || pathFile.find("htm") || pathFile.find("/", 0)){
            //cout << "Path File: " << pathFile << endl;
        }else{
            error = error + ("\nPath File: " + pathFile + " is not a valid path file.");
        }
        //Parameter validation
        if(parameters.find("?")){
            error = error + ("Parameters: " + parameters + " do not start with \'?\'.");
        }
    
    if(error != ""){
        cout << error << endl;
    }else{
        //Display all components
            
        cout << "\nProtocol: " << protocol << endl;
        cout << "Domain: " << domain << endl;
        cout << "Port: " << port << endl;
        cout << "Path File: " << pathFile << endl;
        cout << "Parameters: " << parameters << endl;
    }

}
