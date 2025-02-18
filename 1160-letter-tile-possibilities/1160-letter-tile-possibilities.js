/**
 * @param {string} tiles
 * @return {number}
 */
var numTilePossibilities = function(tiles) {
   let count = 0;
   const vec = new Array(26).fill(0);
   for(const ch of tiles)
   {
    vec[ch.charCodeAt(0)-'A'.charCodeAt(0)]++;

   }
   const solve = (vec)=>{
    count++;
    for(let i= 0;i<26;i++)
    {
        if(vec[i]===0)
        {
            continue;
        }
        vec[i]--;
        solve(vec);
        vec[i]++;
    }
   };
   solve(vec);
   return count -1; 
};