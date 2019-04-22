import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		BigDecimal t,a,b,k;
		BigDecimal L,R,mid,EPS,TWO;
		EPS=BigDecimal.ONE;
		mid=BigDecimal.ONE;
		for(int i=0;i<=100;i++) {
			EPS=EPS.divide(BigDecimal.TEN);
		}
		TWO=BigDecimal.valueOf(2.0);
		L=BigDecimal.ONE; R=TWO;
		while((R.subtract(L)).compareTo(EPS)==1) {
			mid=(L.add(R)).divide(TWO);
			if(((mid.multiply(mid)).subtract(mid).subtract(BigDecimal.ONE)).compareTo(BigDecimal.ZERO)==1){
				R=mid;
			}else {
				L=mid;
			}
		}
		t=mid;
		while(cin.hasNext()) {
			a=cin.nextBigDecimal();
			b=cin.nextBigDecimal();
			if(a.compareTo(b)==1) {
				k=a; a=b; b=k;
			}
			k=b.subtract(a);
			//System.out.println((t.multiply(k)).divide(BigDecimal.ONE,0,BigDecimal.ROUND_DOWN));
			if(a.equals(t.multiply(k).divide(BigDecimal.ONE,0,BigDecimal.ROUND_DOWN))) {
				System.out.println("0");
			}else {
				System.out.println("1");
			}
		}
		cin.close();
	}
}
