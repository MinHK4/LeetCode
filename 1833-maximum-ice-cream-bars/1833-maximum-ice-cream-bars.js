/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {
    costs.sort((a, b) => a-b);
    
    let ans = 0;
    let sum = 0;
    costs.forEach(cost => {
        if(sum + cost <= coins){
            ans++;
            sum += cost;
        }
    })
    
    return ans;
};