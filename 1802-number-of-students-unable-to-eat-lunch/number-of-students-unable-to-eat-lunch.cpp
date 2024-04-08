class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt = students.size() , stu_cir = 0 , stu_san = 0;
        for(int i =0 ; i<students.size();i++){
            if(students[i] == 0) stu_cir++;
            else stu_san++;
        }
        for(int i =0 ; i< sandwiches.size();i++){
            if(sandwiches[i] == 0){
                if(stu_cir > 0){
                    cnt--;
                    stu_cir--;
                }
                else{return cnt;}
            }
            else{
                if(stu_san > 0){
                    cnt--;
                    stu_san--;
                }
                else{return cnt;}
            }
        }
        return cnt;
    }
};