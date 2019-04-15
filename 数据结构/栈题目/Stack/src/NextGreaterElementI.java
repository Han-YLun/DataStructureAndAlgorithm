import java.util.HashMap;
import java.util.Stack;

public class NextGreaterElementI {
    //解法一
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        //用来保存返回的数组
        int[] result = new int[nums1.length];
        //返回的数组length为初始化为0
        int length = 0;
        int i,j;
        int indexI,indexJ;

        for(i=0;i<nums1.length;i++){
             indexI = 0;
            indexJ =0;
            for( j=0;j< nums2.length;j++){
                if(nums1[i] == nums2[j]){
                    //找到值在nums1和num2中的位置,并且分别保存在indexI和indexJ中
                    indexI = i;
                    indexJ = j;
                    break;
                }
            }
            //如果此时j已经是num2中的最后一个元素,那下一个更大的数为-1
            if(j >= nums2.length-1){
                result[length++] = -1;
            }else{
                //否则找出他下一个更大的数保存在数组中
                for(j=indexJ+1;j<nums2.length;j++){
                    if(nums2[j] > nums1[indexI]){
                        result[length++] = nums2[j];
                        break;
                    }
                }
                if(j >= nums2.length){
                    result[length++] = -1;
                }
            }

        }
        return result;
    }


    public int[] nextGreaterElement2(int[] nums1, int[] nums2) {

        Stack<Integer> stack = new Stack<Integer>();
        //将nums2每一个下一个比他大的值都保存在map中
        HashMap<Integer,Integer> map = new HashMap<>();

        //用来返回结果
        int[] result = new int[nums1.length];
        int length = 0;



        for(int i=0;i<nums2.length;i++){
            //如果栈不为空,并且栈顶元素小于当前num2的值,就栈顶元素弹出并和nums2保存在map中
            while (!stack.isEmpty() && stack.peek() < nums2[i]){
                map.put(stack.pop(),nums2[i]);
            }
            stack.add(nums2[i]);

        }

        for (int i = 0; i < nums1.length ; i++) {
            result[length++] = map.getOrDefault(nums1[i],-1);
        }

        return result;

    }


    public static void main(String[] args) {
        int[] nums1 = new int[]{1,3,5,2,4};
        int[] nums2 = new int[]{6,5,4,3,2,1,7};
        int[] ints = new NextGreaterElementI().nextGreaterElement2(nums1, nums2);
        for (int anInt : ints) {
            System.out.println(anInt);
        }
    }
}
