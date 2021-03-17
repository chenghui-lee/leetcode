class Solution {
    private double rad, x, y;
    public Solution(double radius, double x_center, double y_center) {
        rad = radius; x = x_center; y = y_center;
    }
    
    public double[] randPoint() {
        double length = Math.sqrt(Math.random()) * rad;
        double degree = Math.random() * 2 * Math.PI;
        double X = x + length * Math.cos(degree);
        double Y = y + length * Math.sin(degree);
        return new double[]{X, Y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
