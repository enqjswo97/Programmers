class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int zeroCnt = 0, equalCnt = 0;

        for(int l : lottos) {
            if(l == 0) zeroCnt++;
            else{
                for(int w : win_nums) {
                    if(l==w) {
                        equalCnt++;
                        break;
                    }
                }
            }  
        }
        answer[0] = 7 - (zeroCnt + equalCnt);
        answer[1] = 7 - equalCnt;
        
        if(answer[0] > 6) answer[0] = 6;
        if(answer[1] > 6) answer[1] = 6;
        
        return answer;
    }
}