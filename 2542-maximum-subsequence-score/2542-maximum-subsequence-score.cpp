class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        map<long long,vector<long long>>mp;
        priority_queue<long long,vector<long long>, greater<long long>>mnh;
        bool flag=0;
        long long n = nums1.size();
        if(n==k){
            cout<<1<<endl;
            long long sum=0;
            for(auto i:nums1){
                sum += i;
            }
            long long mx = *min_element(nums2.begin(),nums2.end());
            return mx*sum;
        }
        long long ans = LLONG_MIN;
        for(long long i=0; i<n; i++){
            mp[nums2[i]].push_back(i);
        }
        vector<long long>temp;
        sort(nums2.begin(),nums2.end());
        long long sum=0;
        long long x=0;
        long long i=n-1;
        for(i=n-1; i>=n-k; i--){
            if((long long)mp[nums2[i]].size()==1){
                sum += (long long)nums1[mp[nums2[i]][0]];
                mnh.push((long long)nums1[mp[nums2[i]][0]]);
            }
            else{
                for(x=0; x<(long long)mp[nums2[i]].size(); x++){
                    sum += (long long)nums1[mp[nums2[i]][x]];
                    mnh.push((long long)nums1[mp[nums2[i]][x]]);
                    // cout<<mp[nums2[i]].size()<<" ";
                    i--;
                    if(i<n-k){
                        flag=1;
                        x++;
                        cout<<i<<" "<<x<<" ";
                        cout<<mp[nums2[i]].size()<<" ";
                        break;
                    }
                }
                i++;
            }
        }
        ans = (long long)nums2[n-k]*sum;
        cout<<flag<<" ";
        cout<<ans<<" ";
        if(!flag){
            for(long long g=i; g>=0; g--){
                if((long long)mp[nums2[g]].size()==1){
                    if(nums1[mp[nums2[g]][0]]<=mnh.top()){
                        sum -= mnh.top();
                        sum += (long long)nums1[mp[nums2[g]][0]];
                        ans = max(ans,(long long)nums2[g]*sum);
                        sum -= (long long)nums1[mp[nums2[g]][0]];
                        sum += mnh.top();
                    }
                    else{
                        sum -= mnh.top();
                        sum += (long long)nums1[mp[nums2[g]][0]];
                        mnh.pop();
                        mnh.push(nums1[mp[nums2[g]][0]]);
                        ans = max(ans,(long long)nums2[g]*sum);
                    }
                }
                else{
                    for(x=0; x<(long long)mp[nums2[g]].size(); x++){
                        if(nums1[mp[nums2[g]][x]]<=mnh.top()){
                            sum -= mnh.top();
                            sum += (long long)nums1[mp[nums2[g]][x]];
                            ans = max(ans,(long long)nums2[g]*sum);
                            sum -= (long long)nums1[mp[nums2[g]][x]];
                            sum += mnh.top();
                        }
                        else{
                            sum -= mnh.top();
                            sum += (long long)nums1[mp[nums2[g]][x]];
                            mnh.pop();
                            mnh.push(nums1[mp[nums2[g]][x]]);
                            ans = max(ans,(long long)nums2[g]*sum);
                        }
                        g--;
                        if(g<0)break;
                    }
                    g++;
                }
            }
        }
        else{
            cout<<mp[nums2[i+1]].size()<<" "<<x<<" ";
            cout<<mp[nums2[i+1]].size()<<" "<<x<<" ";
            long long size = (long long)mp[nums2[i+1]].size();
            while(x<size){
                if(nums1[mp[nums2[i+1]][x]]>mnh.top()){
                    sum -= mnh.top();
                    sum += (long long)nums1[mp[nums2[i+1]][x]];
                    mnh.pop();
                    mnh.push(nums1[mp[nums2[i+1]][x]]);
                    ans = max(ans,(long long)nums2[i+1]*sum); 
                }
                else{
                    
                    sum -= mnh.top();
                    sum += (long long)nums1[mp[nums2[i+1]][x]];
                    ans = max(ans,(long long)nums2[i+1]*sum); 
                    sum -= (long long)nums1[mp[nums2[i+1]][x]];
                    sum += mnh.top();
                }
                // mn = min(mn,nums1[mp[nums2[i]][x]]);
                // ans = max(ans,(long long)nums2[i]*sum);
                x++;
                i--;
            }
            cout<<2<<endl;
            // cout<<mp[nums2[i]].size()<<" ";
            for(long long g=i; g>=0; g--){
                if((long long)mp[nums2[g]].size()==1){
                    if(nums1[mp[nums2[g]][0]]<=mnh.top()){
                        sum -= mnh.top();
                        sum += (long long)nums1[mp[nums2[g]][0]];
                        ans = max(ans,(long long)nums2[g]*sum);
                        sum -= (long long)nums1[mp[nums2[g]][0]];
                        sum += mnh.top();
                    }
                    else{
                        sum -= mnh.top();
                        sum += (long long)nums1[mp[nums2[g]][0]];
                        mnh.pop();
                        mnh.push(nums1[mp[nums2[g]][0]]);
                        ans = max(ans,(long long)nums2[g]*sum);
                    }
                }
                else{
                    for(x=0; x<(long long)mp[nums2[g]].size(); x++){
                        if(nums1[mp[nums2[g]][x]]<=mnh.top()){
                            sum -= mnh.top();
                            sum += (long long)nums1[mp[nums2[g]][x]];
                            ans = max(ans,(long long)nums2[g]*sum);
                            sum -= (long long)nums1[mp[nums2[g]][x]];
                            sum += mnh.top();
                        }
                        else{
                            sum -= mnh.top();
                            sum += (long long)nums1[mp[nums2[g]][x]];
                            mnh.pop();
                            mnh.push(nums1[mp[nums2[g]][x]]);
                            ans = max(ans,(long long)nums2[g]*sum);
                        }
                    }
                    g -= mp[nums2[g]].size();
                }
            }
        }
        return ans;
    }
};