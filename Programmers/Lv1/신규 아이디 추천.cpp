#include <string>
#include <vector>

using namespace std;



string process7(string new_id){
    if(new_id.size() <= 2){
        while(new_id.size() < 3){
            new_id = new_id + new_id[new_id.size()-1];
        }
    }
    return new_id;
}

string process6(string new_id){
    if(new_id.size() >= 16){
        if(new_id[14] == '.')   return process7(new_id.substr(0, 14));
        else    return process7(new_id.substr(0, 15));
    }
    else{
        return process7(new_id);
    }
}

string process5(string new_id){
    if(new_id.size() == 0)  return process6("a");
    else    return process6(new_id);
}

string process4(string new_id){
    int id_size = new_id.size();
    if(new_id[0] == '.' && new_id[id_size-1] == '.'){
        return process5(new_id.substr(1, id_size-2));
    }
    else if(new_id[0] == '.'){
        return process5(new_id.substr(1));
    }
    else if(new_id[id_size-1] == '.'){
        return process5(new_id.substr(0, id_size-1));
    }
    else{
        return process5(new_id);
    }
}

string process3(string new_id){
    string result = "";
    int id_size = new_id.size();
    for(int i=0;i<id_size;i++){
        if(i == 0)  result += new_id[0];
        else {
            if(new_id[i] != '.' || new_id[i-1] != '.') 
                result = result + new_id[i];
        }
    }
    return process4(result);
}

string process2(string new_id){
    string result = "";
    int id_size = new_id.size();
    for(int i=0;i<id_size;i++){
        if(('a' <= new_id[i] && new_id[i] <= 'z') ||  ('0' <= new_id[i] && new_id[i] <= '9') || (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')){
            result = result + new_id[i];
        }   
    }
    return process3(result);
}

string process1(string new_id){
    int id_size = new_id.size();
    for(int i=0;i<id_size;i++){
        if('A' <= new_id[i] && new_id[i] <= 'Z')
            new_id[i] = (char)(new_id[i] - 'A' + 'a');
    }
    return process2(new_id);
}


string solution(string new_id) {
    string answer = "";
    answer = process1(new_id);
    return answer;
}