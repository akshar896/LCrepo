/**
 * @param {number[]} parent
 * @param {number[]} nums
 * @return {number}
 */
const calc=function(curr,par,depth,adj){
    for(let nbr of adj[curr]){
        if(nbr!=par[curr]){
            depth[nbr]=depth[curr]+1;
            calc(nbr,par,depth,adj);
        }
    }
}
var weightedSum = function(parent, nums) {
    let n=nums.length;
    let depth=new Array(n);
    let adj=Array.from({length:n},()=>[]);
    for(let i=0;i<n;i++){
        if(i==0){
            continue;
        }
        adj[i].push(parent[i]);
        adj[parent[i]].push(i);
    }
    depth[0]=1;
    calc(0,parent,depth,adj);
    let ans=0;
    let h=0;
    for(let dp of depth){
        h=Math.max(h,dp);
    }
    for(let i=0;i<n;i++){
        ans+=nums[i]*h;
        ans+=nums[i];
    }
    for(let i=0;i<n;i++){
        ans-=nums[i]*depth[i];
    }
    return ans;
};