class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/" ){
                long long int kt=st.top();
                st.pop();
                long long int pt=st.top();
                st.pop();
                cout<<kt<<" "<<pt<<endl;
                
                if(tokens[i]=="+"){
                    st.push(kt+pt);
                }else  if(tokens[i]=="*"){
                    st.push(kt*pt);
                }
                else  if(tokens[i]=="-"){
                    st.push(pt-kt);
                }
                else  if(tokens[i]=="/"){
                    st.push(pt/kt);
                }
            }
            else{
                st.push(stoll(tokens[i]));
            }
        }
        if(st.size()!=1)return -1;
        return st.top();
    }
};
