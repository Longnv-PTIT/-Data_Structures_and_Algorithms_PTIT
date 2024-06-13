#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    // tạo contest 
    int t; cin >> t;
    // lặp số lượng contest
    while(t--){
        // tạo chuỗi kí tự 
        string prefix; cin >> prefix;
        // tạo ngăn xếp kiểu string
        stack <string> st;
        // Duyệt chuỗi prefix từ phải sang trái
        for(int i = prefix.size()-1; i >= 0; i--){
            // điều kiện, nếu chuỗi nằm trong khoảng toán hạng A -> Z, thì đẩy vào ngăn xếp
            if(prefix[i] >= 'A' && prefix[i] <='Z'){
                st.push(string(1,prefix[i]));
            }
            //Nếu gặp toán tử thì pop 2 toán hạng ở ngăn xếp ra
            else {
                    string toanhang1 = st.top(); st.pop();
                    string toanhang2 = st.top(); st.pop();
                    //tạo new_prefix trung tố mới rồi đẩy vào ngăn xếp 
                    string new_prefix = "("+ toanhang1 + prefix[i] + toanhang2 +")";
                    st.push(new_prefix);
            }
        }
        cout << st.top() << endl;
    }
}