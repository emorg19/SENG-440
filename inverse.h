typedef int64_t int_type;

//#define matrix3x 3
//#define matrix4x 4
//#define matrix5x 5
//#define matrix6x 6
//#define matrix7x 7
//#define matrix8x 8
//#define matrix9x 9
#define matrix10x 10

#ifdef matrix3x
    int_type matrix[3][3] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 1}};
    float matrix_orig[3][3] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 1}};

    float inv_matrix[3][3] = {{-11.5, 8.0, 2.5,}, {10.0, -7.0, -2.0} ,{-2.5, 2.0, 0.5}};
    float cond_num = 264.00;
    #define size 3
#endif

#ifdef matrix4x
    int_type matrix[4][4] = {{3, 1, 2, 6}, {0, 2, 3, 6}, {1, 3, 5, 4}, {0, 4, 1, 5}};
    float matrix_orig[4][4] = {{3, 1, 2, 6}, {0, 2, 3, 6}, {1, 3, 5, 4}, {0, 4, 1, 5}};

    float inv_matrix[4][4] = {{0.2939, -0.4072, 0.1186, 0.0412}, {-0.0464, -0.3041, 0.1392, 0.3093}, {-0.0722, 0.0825, 0.2165, -0.1856}, {0.0515, 0.2268, -0.1546, -0.0103}};
    float cond_num = 11.19;
    #define size 4
#endif

#ifdef matrix5x
    int_type matrix[5][5] = {{8, 1, -4, -7, 6}, {4, -8, 6, -3, -3}, {-6, -3, 8, 6, -3}, {3, -5, 6, -4, 7}, {-6, -3, 2, 2, 8}};
    float matrix_orig[5][5] = {{8, 1, -4, -7, 6}, {4, -8, 6, -3, -3}, {-6, -3, 8, 6, -3}, {3, -5, 6, -4, 7}, {-6, -3, 2, 2, 8}};

    float inv_matrix[5][5] = {{0.8077, 0.1193, 0.6485, -0.4794, 0.1016}, {-0.2880, -0.2200, -0.1655, 0.3175, -0.2063} ,{-0.2293, -0.1231, -0.0782, 0.2952, -0.1619}, {1.1084, 0.1710, 0.9410, -0.7746, 0.2635}, {0.2780, -0.0050, 0.2086, -0.1206, 0.0984}};

    float cond_num = 84.72;
    #define size 5
#endif

#ifdef matrix6x
    
    int_type matrix[6][6] = {{9,	9,	8,	8,	0,	4}, {2,	8,	0,	5,	4,	8}, {0,	1,	7,	6,	2,	8}, {4,	4,	3,	8,	5,	1}, {5,	9,	0,	8,	7,	0}, {2,	1,	7,	9,	5,	4}};
    float matrix_orig[6][6] = {{9,	9,	8,	8,	0,	4}, {2,	8,	0,	5,	4,	8}, {0,	1,	7,	6,	2,	8}, {4,	4,	3,	8,	5,	1}, {5,	9,	0,	8,	7,	0}, {2,	1,	7,	9,	5,	4}};

    float inv_matrix[6][6] = {{0.2557,  0.7295,   -1.5699, -0.8262,  -0.5438,   1.6318}, {-0.0354, -0.3188,  0.6354, 0.0167,   0.4188, -0.6021}, {0.1301,  0.0277,   -0.3586,  -1.0024,   0.2438,  0.7824},{-0.2804, -0.6661,    1.6518,   2.0143,   0.03750, -2.1946}, {0.1833,  0.6500,   -1.5833,  -1.7333,  -0.0500,   2.1167},{0.0551,   0.3527,   -0.4836,  -0.2024,  -0.28125,  0.5074}};

    float cond_num = 260.10;
    #define size 6
#endif

#ifdef matrix7x

    int_type matrix[7][7] = {{9, 4, 1, 2, 2, 9, 5},{2, 3, 1, 0, 3, 7, 9},{2, 6, 1, 1, 8, 1, 7},{0, 3, 1, 3, 5, 3, 0},{9, 1, 9, 0, 1, 4, 2},{9, 8, 1, 4, 8, 6, 9}, {8, 3, 8, 1, 3, 2, 5}};
    float matrix_orig[7][7] = {{9, 4, 1, 2, 2, 9, 5},{2, 3, 1, 0, 3, 7, 9},{2, 6, 1, 1, 8, 1, 7},{0, 3, 1, 3, 5, 3, 0},{9, 1, 9, 0, 1, 4, 2},{9, 8, 1, 4, 8, 6, 9}, {8, 3, 8, 1, 3, 2, 5}};
        
     float inv_matrix[7][7] = {{-0.2693, -0.0066, -0.1083, -0.1609, 0.3946, 0.3885, -0.4243}, {1.4529, -0.4469, 0.7264, 0.2264, -1.4124, -1.4595, 1.5266}, {0.2040, -0.0224, 0.0757, 0.1283, -0.2606, -0.3197, 0.4099}, {-0.3486, 0.1179, -0.4901, 0.1415, -0.0807, 0.4128, 0.1116}, {-0.7736, 0.1718, -0.1763, -0.0974, 0.9304, 0.7620, -1.0325}, {0.1170, 0.0501, 0.0322, 0.0849, 0.0293, -0.1168, -0.0539}, {-0.2803, 0.1678, -0.1928, -0.0875, 0.07913, 0.2725, -0.0739}};
     float cond_num = 326.3;

     #define size 7

#endif


#ifdef matrix8x

    int_type matrix[8][8] = {{-7, -7, -6,  1,  1, -5, -3,  8}, {-2, -5, -7,  3, -4, -7, -5,  2}, { 7,  0,  9, -8, -6, -7, -4,  6}, {-9, -9, -4,  3, -2,  6, -8, -7}, {-9,  8,  3,  5, -6, -4, -8,  6}, {-9, -4, -2, -3, -8,  1,  2,  8}, { 1, -8, -5, -5, -2, -5, -3,  2}, { 8,  2,  9, -1, -9, -3,  7, -1}};

    float matrix_orig[8][8] = {{-7, -7, -6,  1,  1, -5, -3,  8}, {-2, -5, -7,  3, -4, -7, -5,  2}, { 7,  0,  9, -8, -6, -7, -4,  6}, {-9, -9, -4,  3, -2,  6, -8, -7}, {-9,  8,  3,  5, -6, -4, -8,  6}, {-9, -4, -2, -3, -8,  1,  2,  8}, { 1, -8, -5, -5, -2, -5, -3,  2}, { 8,  2,  9, -1, -9, -3,  7, -1}};
        
     float inv_matrix[8][8] = {{-0.0924, 0.2934, 0.1771, -0.0152, -0.1851, 0.0815, -0.3433, -0.1282}, {-0.0886, -0.0188, -0.0450, -0.0526, 0.0670, 0.0072, 0.0797, -0.0286}, {0.1171, -0.1474, -0.0042, 0.0477, 0.0489, -0.0715, 0.0437, 0.0920}, {0.0391, 0.2035, 0.0876, 0.0228, -0.1088, 0.0207, -0.3127, -0.0260}, {0.0961, -0.1302, -0.0404, -0.0051, 0.0342, -0.0819, 0.0826, 0.0171}, {-0.1114, 0.2583, 0.1824, 0.0196, -0.1929, 0.1497, -0.3962, -0.1696}, {0.0604, -0.1350, -0.1203, -0.0272, 0.0527, -0.0249, 0.1538, 0.1058}, {-0.0094, 0.2314, 0.1755, -0.0238, -0.1581, 0.1158, -0.3590, -0.1333}};
     float cond_num = 72.52;

     #define size 8

#endif

#ifdef matrix9x
    int_type matrix[9][9] = {{-6,  7, -6,  1, -1, -6, -7, -1, -5}, {-9, -3,  7,  4, -2,  8, -8, -6, -5}, {-5,  7,  2,  6, -9,  3,  9, -5, -6}, { 0, -5,  7,  0,  3,  7, -8, -6,  4}, { 8,  7,  9, -9, -9, -2,  5,  7, -4}, {-4,  2, -7, -7, -5, -9,  3, -9, -6}, { 5,  3, -1, -5, -1,  7,  2,  9,  3}, { 4, -1, -1,  6,  0,  7,  7, -7,  4}, {-6, -3,  2,  3,  8,  5, -2,  0,  1}};

    float matrix_orig[9][9] = {{-6,  7, -6,  1, -1, -6, -7, -1, -5}, {-9, -3,  7,  4, -2,  8, -8, -6, -5}, {-5,  7,  2,  6, -9,  3,  9, -5, -6}, { 0, -5,  7,  0,  3,  7, -8, -6,  4}, { 8,  7,  9, -9, -9, -2,  5,  7, -4}, {-4,  2, -7, -7, -5, -9,  3, -9, -6}, { 5,  3, -1, -5, -1,  7,  2,  9,  3}, { 4, -1, -1,  6,  0,  7,  7, -7,  4}, {-6, -3,  2,  3,  8,  5, -2,  0,  1}};


    float inv_matrix[9][9] = {{0.0632,	0.0952,	-0.1602,	-0.1173,	0.1013,	-0.0140,	-0.0428,	0.1886,	-0.0047}, {0.0975,	-0.0844,	0.0550,	0.0833,	0.0376,	-0.0075,	0.0155,	0.0149,	0.0613}, {-0.0204,	-0.0468,	0.0508,	0.0686,	0.0327,	-0.0233,	-0.0479,	-0.0510,	0.0335}, {0.0193,	0.0238,	-0.0060	-0.0521,	-0.0099,	-0.0678,	-0.0530,	0.0348,	-0.0390}, {0.0674,	0.0162,	-0.1024	-0.0659,	0.0931,	0.0157,	-0.0415,	0.1256,	0.1564}, {0.0168,	0.0717,	-0.0415	-0.0392,	0.0179,	0.0169,	0.0632,	0.0768,	0.0267}, {-0.0500,	-0.0335,	0.0378,	-0.0162,	0.0013,	0.0211,	-0.0037,	-0.0078,	0.0482}, {-0.0308,	0.0086,	0.0115,	-0.0425,	-0.0255,	-0.0379,	0.0244,	-0.0631,	-0.0222}, {-0.0686,	-0.2155,	0.2221,	0.2560,	-0.1471,	-0.0247,	0.0528,	-0.2310,	-0.0829}};
    
    float cond_num = 78.04;
    #define size 9


#endif

#ifdef matrix10x
    int_type matrix[10][10] = {{1, -1, 0, -4, 0, -1, 3, 3, 4, -1}, {-2, 1, -2, 3, -3, -1, 4, -2, -2, -2}, {-3, 3, 2, 1, 0, -3, -1, -2, 2, 1}, {4, 0, -1, 4, -2, 2, -1, 0, 2, -2}, {-4, 1, -4, -2, 0, -3, -2, 0, 3, -4}, {2, 2, 1, 2, 0, -1, -4, 1, 3, -3}, {2, -1, -4, 1, -3, -1, 1, -1, -1, -1}, {4, -3, 4, -1, 0, -1, 3, -1, 3, 0}, {-1, -2, -1, -2, -1, -1, 2, -3, 0, -2}, {-3, -2, 1, 3, 0, -4, -2, -4, 2, 2}};

    float matrix_orig[10][10] = {{1, -1, 0, -4, 0, -1, 3, 3, 4, -1}, {-2, 1, -2, 3, -3, -1, 4, -2, -2, -2}, {-3, 3, 2, 1, 0, -3, -1, -2, 2, 1}, {4, 0, -1, 4, -2, 2, -1, 0, 2, -2}, {-4, 1, -4, -2, 0, -3, -2, 0, 3, -4}, {2, 2, 1, 2, 0, -1, -4, 1, 3, -3}, {2, -1, -4, 1, -3, -1, 1, -1, -1, -1}, {4, -3, 4, -1, 0, -1, 3, -1, 3, 0}, {-1, -2, -1, -2, -1, -1, 2, -3, 0, -2}, {-3, -2, 1, 3, 0, -4, -2, -4, 2, 2}};

    float inv_matrix[10][10] = {{-0.3233, -0.0753, 0.0753, 0.0021, 0.2936, -0.1881, 0.1809, 0.4161, -0.3210, -0.1980}, {-0.2538,   -0.0362,    0.2668,    0.0590,    0.2572,   -0.2183,    0.0794,    0.2572,   -0.2477,   -0.2586}, { 0.3532,    0.0646,   -0.0564,   -0.1205,   -0.5043,    0.4337,   -0.1321,   -0.3956,    0.4437,    0.1685}, {-0.1747,    0.1283,   -0.0903,    0.0580,    0.2101,   -0.1242,   -0.0584,    0.2193,   -0.3258,    0.0230}, {-0.9291,    0.0002,   -0.0102,    0.0528,    1.0936,   -0.7491,   -0.0271,    1.1113,   -1.0250,   -0.3814}, { 0.1296,   -0.0679,    0.0316,    0.2412,   -0.1572,   -0.0577,   -0.1843,   -0.2488,    0.2743,    0.0035}, {-0.2325,    0.1040,    0.0397,    0.0504,    0.3411,   -0.3233,   -0.0179,    0.3971,   -0.3591,   -0.1525}, { 0.3572,    0.1109,   -0.1960,   -0.1441,   -0.2955,    0.3115,   -0.0392,   -0.3202,    0.0733,    0.1733}, { 0.0428,   -0.0688,    0.1170,    0.2182,    0.1160,   -0.1792,   -0.0617,    0.0496,   -0.0449,   -0.0001}, { 0.0451,   -0.1152,    0.1372,    0.0618,   -0.0457,   -0.1675,    0.1012,   -0.0405,   -0.0815,    0.0269}};
    float cond_num = 123.74;

    #define size 10
#endif

#ifdef bad_matrix
    int_type matrix[3][3] = {{1, 0, 2}, {1, 0, 4}, {1, 0, 6}};
    float inv_matrix[3][3] = {{0, 0, 0,}, {0,0,0}, {0, 0, 0}};
    #define size 3
#endif

void augment();
void swap(int row1, int row2);
int max_column(int col);
void eliminate();
void normalize();
void print_fractional();
void deaugment();
void print(int_type a[size][size*2]);
void print_square(int_type a[size][size]);
void end_timer(clock_t start_time);