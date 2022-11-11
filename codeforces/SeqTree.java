public class SeqTree{
    class Node{
        Node left, right;
        int val; // 当前节点值
        int add; // 懒惰标记
    }
    // leftNum和rightNum 表示左右孩子区间的叶子节点数量
    private void pushDown(Node node,int leftNum,int rightNum){
        if(node.left == null) node.left = new Node();
        if(node.right == null) node.right = new Node();
        if(node.add == 0) return;
        // 否则进行下推
        node.left.val += node.add * leftNum;
        node.right.val += node.add * rightNum;
        node.left.add += node.add;
        node.right.add += node.add;
        // 取消当前节点的标记
        node.add = 0;
    }
    // 对区间[start,end]中更新区间l,r的值，将区间[l,r]中的值加val
    public void update(Node node,int start,int end,int l,int r,int val){
        if(l<=start&&end<=r){
            node.val += (end - start + 1) * val;
            node.add += val;
            return;
        }
        int mid = (start + end) >> 1;
        pushDown(node, mid - start + 1, end - mid);
        if(l<=mid) update(node.left, start, mid, l, r, val);
        if(r>mid) update(node.right, mid+1, end, l, r, val);
        pushUp(node);
    }
    private void pushUp(Node node){
        node.val = node.left.val + node.right.val;
    }

    public int query(Node node,int start,int end,int l,int r){
        if(l<=start&&end<=r) return node.val;
        int mid = (start + end) >> 1,ans = 0;
        pushDown(node, mid - start + 1, end - mid);
        if(l<=mid) ans += query(node.left, start, mid, l, r);
        if(r<=mid) ans += query(node.right, mid + 1, end, l, r);
        return ans;
    }
    public static void main(String[] args) {
        
    }
}