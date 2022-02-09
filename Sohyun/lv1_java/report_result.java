import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        //map ����
        Map<String, Integer> reportNum = new LinkedHashMap<>(); //�Ű���� Ƚ��
        Map<String, Integer> ret = new LinkedHashMap<>(); //���Ϲ޴� ��
            
        //map �ʱ�ȭ
        for(String id : id_list) {
            reportNum.put(id,0);
            ret.put(id,0);
        }
        
        //�ߺ����� (set �̿�)
        HashSet<String> hashSet = new HashSet<>(Arrays.asList(report));
        report = hashSet.toArray(new String[0]);
        
        //�Ű� ���� Ƚ�� ī��Ʈ
        for(String re : report) {
            String[] temp = re.split(" ");
            reportNum.put(temp[1],reportNum.get(temp[1]) + 1);
        }
        
        //map ��ȸ (�Ű���� �̻��� ��� üũ)
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
        
        //���ٷ� ǥ��
        return ret.values().stream().mapToInt(Integer::intValue).toArray();
    }
}


