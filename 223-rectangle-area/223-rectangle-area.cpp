class Solution {
private: 
//     bool overlapping(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
//         return ((ax2 <= bx1) || (bx2 <= ax1) || (by1 <= ay2) || (by2 <= ay1));
//     }
public:
//     int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
//         int area1 = (ax2 - ax1) * (ay2 - ay1);
//         int area2 = (bx2 - bx1) * (by2 - by1);
//         int oarea = 0;

//         if(overlapping(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)){
//             int lby = max(ay1, by1);
//             int uby = min(ay2, by2);
            
//             int lbx = max(ax1, bx1);
//             int ubx = min(ax2, bx2);
//             oarea = (ubx - lbx) * (uby - lby);
//         }
//         return area1 + area2 - oarea;
        
//     }
    
    bool CheckOverlap(int rec1L, int rec1D, int rec1R, int rec1T, 
                  int rec2L, int rec2D, int rec2R, int rec2T)
    {
        return (min(rec1R, rec2R) > max(rec1L, rec2L) && min(rec1T, rec2T) > max(rec1D, rec2D));
    }

    int computeArea(int rec1L, int rec1D, int rec1R, int rec1T, 
                    int rec2L, int rec2D, int rec2R, int rec2T) 
    {

        int rec1Area = (rec1R - rec1L) * (rec1T - rec1D);
        int rec2Area = (rec2R - rec2L) * (rec2T - rec2D);

        bool f = CheckOverlap(rec1L, rec1D, rec1R, rec1T, 
                              rec2L, rec2D, rec2R, rec2T);

        if (!f) return rec1Area + rec2Area;

        int h = min(rec1T, rec2T) - max(rec1D, rec2D);
        int w = min(rec1R, rec2R) - max(rec1L, rec2L);

        return rec1Area + rec2Area - h * w;
    }
};