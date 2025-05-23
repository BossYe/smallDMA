# 寄存器字段

## 寄存器表

当前的寄存器布局如下表所示：

| 地址   | 作用             |
| ------ | ---------------- |
| `0x00` | [控制寄存器]     |
| `0x04` | [状态寄存器]     |
| `0x08` | [中断屏蔽寄存器] |
| `0x0c` | [中断状态寄存器] |
| `0x10` | [读模块起始地址] |
| `0x14` | [读模块行长度]   |
| `0x18` | [读模块行数]     |
| `0x1c` | [读模块行间距]   |
| `0x20` | [写模块起始地址] |
| `0x24` | [写模块行长度]   |
| `0x28` | [写模块行数]     |
| `0x2c` | [写模块行间距]   |
| `0x30` | [版本寄存器]     |
| `0x34` | [配置寄存器]     |

## 寄存器详细说明

### 控制寄存器（0x00）

| 位   | 名称           | 描述                                                        |
| ---- | -------------- | ----------------------------------------------------------- |
| 0    | 写模块启动     | 写入 `1` 启动写前端（非循环模式下会自动重置为 `0`）         |
| 1    | 读模块启动     | 写入 `1` 启动读前端（非循环模式下会自动重置为 `0`）         |
| 2    | 禁用写同步     | 写入 `1` 禁用等待外部写同步（即忽略 `writerSync` 的上升沿） |
| 3    | 禁用读同步     | 写入 `1` 禁用等待外部读同步（即忽略 `readerSync` 的上升沿） |
| 4    | 写模块循环模式 | 写入 `1` 在当前传输完成后自动开始下一次写传输               |
| 5    | 读模块循环模式 | 写入 `1` 在当前传输完成后自动开始下一次读传输               |
| 6-31 | —              | 未使用                                                      |

---

### 状态寄存器（0x04）

| 位   | 名称     | 描述                              |
| ---- | -------- | --------------------------------- |
| 0    | 写模块忙 | 为 `1` 表示写前端正在进行数据传输 |
| 1    | 读模块忙 | 为 `1` 表示读前端正在进行数据传输 |
| 2-31 | —        | 未使用                            |

---

### 中断屏蔽寄存器（0x08）

| 位   | 名称       | 描述                      |
| ---- | ---------- | ------------------------- |
| 0    | 写中断屏蔽 | 写入 `1` 以使能写模块中断 |
| 1    | 读中断屏蔽 | 写入 `1` 以使能读模块中断 |
| 2-31 | —          | 未使用                    |

---

### 中断状态寄存器（0x0c）

| 位   | 名称       | 描述                                               |
| ---- | ---------- | -------------------------------------------------- |
| 0    | 写中断状态 | 为 `1` 表示写模块中断已触发，写入 `1` 可清除该中断 |
| 1    | 读中断状态 | 为 `1` 表示读模块中断已触发，写入 `1` 可清除该中断 |
| 2-31 | —          | 未使用                                             |

---

### 读模块起始地址（0x10）

| 位   | 名称     | 描述                                         |
| ---- | -------- | -------------------------------------------- |
| 0-31 | 起始地址 | 读模块的起始地址（如果是流接口则设置为 `0`） |

---

### 读模块行长度（0x14）

| 位   | 名称   | 描述                                 |
| ---- | ------ | ------------------------------------ |
| 0-31 | 行长度 | 以“读数据总线宽度”的单位表示的行长度 |

---

### 读模块行数（0x18）

| 位   | 名称 | 描述         |
| ---- | ---- | ------------ |
| 0-31 | 行数 | 读模块的行数 |

---

### 读模块行间距（0x1c）

| 位   | 名称   | 描述                                         |
| ---- | ------ | -------------------------------------------- |
| 0-31 | 行间距 | 连续两行之间的间隔（以读数据总线宽度为单位） |

---

### 写模块起始地址（0x20）

| 位   | 名称     | 描述                                         |
| ---- | -------- | -------------------------------------------- |
| 0-31 | 起始地址 | 写模块的起始地址（如果是流接口则设置为 `0`） |

---

### 写模块行长度（0x24）

| 位   | 名称   | 描述                                 |
| ---- | ------ | ------------------------------------ |
| 0-31 | 行长度 | 以“写数据总线宽度”的单位表示的行长度 |

---

### 写模块行数（0x28）

| 位   | 名称 | 描述         |
| ---- | ---- | ------------ |
| 0-31 | 行数 | 写模块的行数 |

---

### 写模块行间距（0x2c）

| 位   | 名称   | 描述                                         |
| ---- | ------ | -------------------------------------------- |
| 0-31 | 行间距 | 连续两行之间的间隔（以写数据总线宽度为单位） |

---

### 版本寄存器（0x30）

| 位   | 名称       | 描述             |
| ---- | ---------- | ---------------- |
| 0-31 | 版本寄存器 | 保存 DMA的版本号 |

---

### 配置寄存器（0x34）

| 位   | 名称       | 描述                       |
| ---- | ---------- | -------------------------- |
| 0-31 | 配置寄存器 | 读写控制通道类型的配置信息 |

