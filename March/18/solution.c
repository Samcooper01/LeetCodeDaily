int min_func(int a, int b) {
    if(a > b) {
        return b;
    }
    else if (b > a) {
        return a;
    }
    else {
        return a;
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    //First, Sort the array
    int points_sorted[pointsSize][*pointsColSize];
    int sorted_index = 0;
    int MAX_INT = 99999999999;

    for(int i = 0; i < pointsSize; i++) {
        int min_index = 0;
        int min_size = points[0][0];
        for(int i = 1; i < pointsSize; i++) {
            if((min_size > points[i][0])) {
                min_size = points[i][0];
                min_index = i;
            }
        }
        points_sorted[sorted_index][0] = points[min_index][0];
        points_sorted[sorted_index][1] = points[min_index][1];
        points[min_index][0] = MAX_INT;
        points[min_index][1] = MAX_INT;
        sorted_index++;
    }

    int end_point = points_sorted[0][1];
    int num_arrows = 1;

    for(int i = 1; i < pointsSize; i++) {
        if(points_sorted[i][0] > end_point) {
            num_arrows++;
            end_point = points_sorted[i][1];
        }
        else {
            end_point = min_func(end_point, points_sorted[i][1]);
        }
    }


    return num_arrows;
}