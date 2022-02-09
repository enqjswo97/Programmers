import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        //map 선언
        Map<String, Integer> reportNum = new LinkedHashMap<>(); //신고당한 횟수
        Map<String, Integer> ret = new LinkedHashMap<>(); //메일받는 수
            
        //map 초기화
        for(String id : id_list) {
            reportNum.put(id,0);
            ret.put(id,0);
        }
        
        //중복제거 (set 이용)
        HashSet<String> hashSet = new HashSet<>(Arrays.asList(report));
        report = hashSet.toArray(new String[0]);
        
        //신고 당한 횟수 카운트
        for(String re : report) {
            String[] temp = re.split(" ");
            reportNum.put(temp[1],reportNum.get(temp[1]) + 1);
        }
        
        //map 조회 (신고기준 이상인 경우 체크)
        Set<String> keySet = reportNum.keySet();
        for(String key : keySet) {
            if(reportNum.get(key) >= k) {
                for(String re : report) {
                    String[] temp = re.split(" ");
                    if(temp[1].equals(key)) 
                        ret.put(temp[0], ret.get(temp[0]) + 1);
                }
            }
        }
        
        int cnt = 0;
        keySet = ret.keySet();
        for(String key : keySet) answer[cnt++] = ret.get(key);
        return answer;
        
        //한줄로 표현
        return ret.values().stream().mapToInt(Integer::intValue).toArray();
    }
}


