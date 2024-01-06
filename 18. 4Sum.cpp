// int n = nums.size();
        // set< vector<int> > st;

        // for(int i=0; i<n-2; i++)
        // {
        //     for(int j=i+1; j<n-1; j++)
        //     {
        //         set<long long> hashSet;
        //         for(int k = j+1; k<n; k++)
        //         {
        //             long long sum = nums[i] + nums[j];
        //             sum += nums[k];

        //             long long fourth = target - sum;

        //             if(hashSet.find(fourth) != hashSet.end())
        //             {
        //                 vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }

        //             hashSet.insert(nums[k]);
        //         }
        //     }
        // }


        // vector<vector<int>> ans (st.begin(), st.end());

        // return ans;


            /* second approach */

        
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 4) return ans;


        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int k = j+1;
                int l = n - 1;

                while(k < l)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        
                        while(k<l && nums[k] == nums[k+1]){
                            k++;
                        }
                        while(k<l && nums[l] == nums[l-1]){
                            l--;
                        }

                        k++;
                        l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }

            }
        }

        return ans;
