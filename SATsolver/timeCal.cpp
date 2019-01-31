//
//  timeCal.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/31.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  时间计算模块
//

#include <time.h>
#include "SATsolver.h"

/*
 * 函数名称: timeCal
 * 接受参数: clock_t类型的值t1, t2
 * 函数功能: 计算t1, t2之间的时间, 以毫秒为单位保存在timeConsumed
 * 返回值: void
 */
void timeCal(clock_t t1, clock_t t2) {
    timeConsumed = (int)(t2 - t1) * 1000 / CLOCKS_PER_SEC;
}
