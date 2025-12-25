// 可视化迷宫问题Java代码（基于Swing框架实现）
// 作者：何沛霖  编写环境：JDK17
import javax.swing.*;
import javax.swing.Timer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import java.util.List;

public class MazeSolverVisualization extends JFrame {
    // 迷宫数据
    private int[][] maze;
    private int rows, cols;
    private Point start, end;

    // 可视化组件
    private MazePanel mazePanel;
    private PathPanel pathPanel;
    private ControlPanel controlPanel;

    // 算法状态
    private List<Point> currentPath;
    private List<Point> visited;
    private List<Point> solutionPath;  // 修正：应该是List<Point>而不是boolean<Point>
    private boolean isSolving = false;
    private Timer timer;
    private int animationSpeed = 100; // 毫秒
    private boolean useCustomMaze = false;

    public MazeSolverVisualization() {
        initializeDefaultMaze();
        setupUI();
        setupTimer();
    }

    private void initializeDefaultMaze() {
        // 默认迷宫数据
        rows = 5;
        cols = 5;
        maze = new int[rows][cols];

        // 示例迷宫 (0-可走, 1-墙)
        int[][] sampleMaze = {
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 1},
                {1, 1, 0, 0, 0},
                {0, 0, 0, 1, 0}
        };

        maze = sampleMaze;
        start = new Point(0, 0);
        end = new Point(4, 4);
        resetSolvingState();
    }

    private void resetSolvingState() {
        currentPath = new ArrayList<>();
        visited = new ArrayList<>();
        solutionPath = new ArrayList<>();  // 修正：初始化solutionPath
        isSolving = false;
        if (timer != null) timer.stop();
    }

    private void setupUI() {
        setTitle("迷宫问题");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // 创建上部面板（包含数据输入和可视化）
        JSplitPane topSplitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
        topSplitPane.setDividerLocation(300);
        topSplitPane.setResizeWeight(0.3);

        // 数据输入面板
        controlPanel = new ControlPanel();
        topSplitPane.setLeftComponent(new JScrollPane(controlPanel));

        // 可视化面板
        mazePanel = new MazePanel();
        topSplitPane.setRightComponent(mazePanel);

        add(topSplitPane, BorderLayout.CENTER);

        // 当前路径面板
        pathPanel = new PathPanel();
        JScrollPane scrollPane = new JScrollPane(pathPanel);
        scrollPane.setBorder(BorderFactory.createTitledBorder("当前路径的实况链表"));
        scrollPane.setPreferredSize(new Dimension(800, 150));
        add(scrollPane, BorderLayout.SOUTH);

        pack();
        setSize(1000, 700);
        setLocationRelativeTo(null);
    }

    private void setupTimer() {
        timer = new Timer(animationSpeed, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (isSolving) {
                    solveStep();
                }
            }
        });
    }

    // 解析迷宫数据输入（仿照C++代码的输入格式）
    private boolean parseMazeData(String input) {
        try {
            String[] lines = input.split("\n");
            if (lines.length < 2) return false;

            // 解析第一行：n m
            String[] firstLine = lines[0].trim().split("\\s+");
            if (firstLine.length != 2) return false;
            rows = Integer.parseInt(firstLine[0]);
            cols = Integer.parseInt(firstLine[1]);

            if (rows <= 0 || cols <= 0 || rows > 20 || cols > 20) {
                JOptionPane.showMessageDialog(this, "迷宫大小必须在1-20之间");
                return false;
            }

            // 解析迷宫数据
            if (lines.length < 1 + rows) return false;
            maze = new int[rows][cols];

            for (int i = 0; i < rows; i++) {
                String[] rowData = lines[i + 1].trim().split("\\s+");
                if (rowData.length != cols) return false;

                for (int j = 0; j < cols; j++) {
                    int value = Integer.parseInt(rowData[j]);
                    if (value != 0 && value != 1) return false;
                    maze[i][j] = value;
                }
            }

            // 解析起点终点
            if (lines.length < 1 + rows + 1) return false;
            String[] lastLine = lines[1 + rows].trim().split("\\s+");
            if (lastLine.length != 4) return false;

            int sx = Integer.parseInt(lastLine[0]) - 1; // 转换为0-based索引
            int sy = Integer.parseInt(lastLine[1]) - 1;
            int ex = Integer.parseInt(lastLine[2]) - 1;
            int ey = Integer.parseInt(lastLine[3]) - 1;

            // 检查起点终点是否合法
            if (sx < 0 || sx >= rows || sy < 0 || sy >= cols ||
                    ex < 0 || ex >= rows || ey < 0 || ey >= cols) {
                JOptionPane.showMessageDialog(this, "起点或终点坐标越界");
                return false;
            }

            if (maze[sx][sy] == 1 || maze[ex][ey] == 1) {
                JOptionPane.showMessageDialog(this, "起点或终点不能是墙");
                return false;
            }

            start = new Point(sx, sy);
            end = new Point(ex, ey);

            useCustomMaze = true;
            return true;

        } catch (Exception e) {
            return false;
        }
    }

    // 回溯法求解迷宫（仿照C++代码的逻辑）
    private void solveStep() {
        if (currentPath.isEmpty()) {
            currentPath.add(start);
            visited.add(start);
            updateDisplay();
            return;
        }

        Point current = currentPath.get(currentPath.size() - 1);

        if (current.equals(end)) {
            timer.stop();
            isSolving = false;
            controlPanel.setSolvingStatus(false);
            solutionPath = new ArrayList<>(currentPath);
            JOptionPane.showMessageDialog(this, "找到路径！路径长度: " + currentPath.size());
            return;
        }

        // 四个方向: 左、上、右、下（与C++代码顺序一致）
        int[][] directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        boolean foundNext = false;

        for (int[] dir : directions) {
            int nx = current.x + dir[0];
            int ny = current.y + dir[1];
            Point next = new Point(nx, ny);

            if (isValidMove(next) && !visited.contains(next)) {
                currentPath.add(next);
                visited.add(next);
                foundNext = true;
                break;
            }
        }

        if (!foundNext) {
            // 回溯
            if (currentPath.size() > 1) {
                currentPath.remove(currentPath.size() - 1);
            } else {
                timer.stop();
                isSolving = false;
                controlPanel.setSolvingStatus(false);
                JOptionPane.showMessageDialog(this, "无解！");
                return;
            }
        }

        updateDisplay();
    }

    private boolean isValidMove(Point p) {
        return p.x >= 0 && p.x < rows && p.y >= 0 && p.y < cols && maze[p.x][p.y] == 0;
    }

    private void updateDisplay() {
        mazePanel.repaint();
        pathPanel.updatePath(currentPath);
    }

    // 迷宫可视化面板
    class MazePanel extends JPanel {
        private static final int CELL_SIZE = 40;

        public MazePanel() {
            setPreferredSize(new Dimension(cols * CELL_SIZE + 100, rows * CELL_SIZE + 100));
            setBorder(BorderFactory.createTitledBorder("迷宫可视化"));
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            int offsetX = 50;
            int offsetY = 50;

            // 绘制迷宫
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int x = j * CELL_SIZE + offsetX;
                    int y = i * CELL_SIZE + offsetY;

                    if (maze[i][j] == 1) {
                        g2d.setColor(Color.DARK_GRAY); // 墙
                        g2d.fillRect(x, y, CELL_SIZE, CELL_SIZE);
                    } else {
                        g2d.setColor(Color.WHITE); // 通路
                        g2d.fillRect(x, y, CELL_SIZE, CELL_SIZE);
                    }
                    g2d.setColor(Color.GRAY);
                    g2d.drawRect(x, y, CELL_SIZE, CELL_SIZE);

                    // 显示坐标
                    g2d.setColor(Color.BLACK);
                    g2d.setFont(new Font("Arial", Font.PLAIN, 10));
                    g2d.drawString((i+1) + "," + (j+1), x + 2, y + 12);

                    // 标记起点和终点
                    if (i == start.x && j == start.y) {
                        g2d.setColor(Color.GREEN);
                        g2d.fillOval(x + 5, y + 5, CELL_SIZE - 10, CELL_SIZE - 10);
                        g2d.setColor(Color.BLACK);
                        g2d.drawString("起点", x + CELL_SIZE/2 - 10, y + CELL_SIZE/2);
                    } else if (i == end.x && j == end.y) {
                        g2d.setColor(Color.RED);
                        g2d.fillOval(x + 5, y + 5, CELL_SIZE - 10, CELL_SIZE - 10);
                        g2d.setColor(Color.BLACK);
                        g2d.drawString("终点", x + CELL_SIZE/2 - 10, y + CELL_SIZE/2);
                    }
                }
            }

            // 绘制最终解路径（如果找到）
            if (!solutionPath.isEmpty()) {
                g2d.setColor(new Color(0, 100, 0)); // 深绿色表示最终路径
                g2d.setStroke(new BasicStroke(3));
                for (int i = 0; i < solutionPath.size(); i++) {
                    Point p = solutionPath.get(i);
                    int x = p.y * CELL_SIZE + offsetX + CELL_SIZE / 2;
                    int y = p.x * CELL_SIZE + offsetY + CELL_SIZE / 2;

                    g2d.fillOval(x - 5, y - 5, 10, 10);

                    if (i > 0) {
                        Point prev = solutionPath.get(i - 1);
                        int prevX = prev.y * CELL_SIZE + offsetX + CELL_SIZE / 2;
                        int prevY = prev.x * CELL_SIZE + offsetY + CELL_SIZE / 2;
                        g2d.drawLine(prevX, prevY, x, y);
                    }
                }
            }

            // 绘制当前搜索路径
            g2d.setColor(Color.BLUE);
            g2d.setStroke(new BasicStroke(2));
            for (int i = 0; i < currentPath.size(); i++) {
                Point p = currentPath.get(i);
                int x = p.y * CELL_SIZE + offsetX + CELL_SIZE / 2;
                int y = p.x * CELL_SIZE + offsetY + CELL_SIZE / 2;

                g2d.fillOval(x - 4, y - 4, 8, 8);

                if (i > 0) {
                    Point prev = currentPath.get(i - 1);
                    int prevX = prev.y * CELL_SIZE + offsetX + CELL_SIZE / 2;
                    int prevY = prev.x * CELL_SIZE + offsetY + CELL_SIZE / 2;
                    g2d.drawLine(prevX, prevY, x, y);
                }
            }

            // 绘制已访问但不在路径上的点
            g2d.setColor(new Color(200, 200, 255, 150));
            for (Point p : visited) {
                if (!currentPath.contains(p) && !solutionPath.contains(p)) {
                    int x = p.y * CELL_SIZE + offsetX + CELL_SIZE / 2;
                    int y = p.x * CELL_SIZE + offsetY + CELL_SIZE / 2;
                    g2d.fillOval(x - 3, y - 3, 6, 6);
                }
            }
        }
    }

    // 路径显示面板
    class PathPanel extends JPanel {
        private JTextArea pathTextArea;

        public PathPanel() {
            setLayout(new BorderLayout());
            pathTextArea = new JTextArea(6, 50);
            pathTextArea.setEditable(false);
            pathTextArea.setFont(new Font("Monospaced", Font.PLAIN, 12));
            add(new JScrollPane(pathTextArea), BorderLayout.CENTER);
        }

        public void updatePath(List<Point> path) {
            StringBuilder sb = new StringBuilder();
            sb.append("当前路径长度: ").append(path.size()).append("\n");
            sb.append("路径序列: ");

            for (int i = 0; i < path.size(); i++) {
                Point p = path.get(i);
                sb.append("(").append(p.x + 1).append(",").append(p.y + 1).append(")");
                if (i < path.size() - 1) sb.append("->");
                if (i % 5 == 4) sb.append("\n           "); // 换行显示
            }

            pathTextArea.setText(sb.toString());
            pathTextArea.setCaretPosition(0);
        }
    }

    // 控制面板（支持数据流输入）
    class ControlPanel extends JPanel {
        private JButton startButton, pauseButton, resetButton, stepButton, loadDataButton;
        private JSlider speedSlider;
        private JTextArea dataInputArea;
        private JLabel statusLabel;

        public ControlPanel() {
            setLayout(new BorderLayout(5, 5));
            setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

            // 数据输入区域
            JPanel dataPanel = new JPanel(new BorderLayout());
            dataPanel.setBorder(BorderFactory.createTitledBorder("迷宫数据输入"));

            JLabel helpLabel = new JLabel("<html>输入格式：<br>"
                    + "第一行: n m (行列数)<br>"
                    + "接下来n行: 每行m个整数(0/1)<br>"
                    + "最后一行: sx sy ex ey (起点终点坐标)</html>");
            dataPanel.add(helpLabel, BorderLayout.NORTH);

            dataInputArea = new JTextArea(10, 20);
            dataInputArea.setFont(new Font("Monospaced", Font.PLAIN, 12));
            dataInputArea.setText(getDefaultInputData());
            dataPanel.add(new JScrollPane(dataInputArea), BorderLayout.CENTER);

            loadDataButton = new JButton("加载迷宫数据");
            dataPanel.add(loadDataButton, BorderLayout.SOUTH);

            add(dataPanel, BorderLayout.NORTH);

            // 控制按钮区域
            JPanel controlArea = new JPanel();
            controlArea.setLayout(new BoxLayout(controlArea, BoxLayout.Y_AXIS));
            controlArea.setBorder(BorderFactory.createTitledBorder("求解控制"));

            // 速度控制
            JPanel speedPanel = new JPanel(new FlowLayout());
            speedPanel.add(new JLabel("动画速度:"));
            speedSlider = new JSlider(10, 500, animationSpeed);
            speedSlider.setMajorTickSpacing(100);
            speedSlider.setPaintTicks(true);
            speedSlider.setPaintLabels(true);
            speedPanel.add(speedSlider);
            controlArea.add(speedPanel);

            // 按钮面板
            JPanel buttonPanel = new JPanel(new GridLayout(2, 2, 5, 5));
            startButton = new JButton("开始求解");
            pauseButton = new JButton("暂停");
            resetButton = new JButton("重置");
            stepButton = new JButton("单步执行");

            pauseButton.setEnabled(false);

            buttonPanel.add(startButton);
            buttonPanel.add(pauseButton);
            buttonPanel.add(resetButton);
            buttonPanel.add(stepButton);

            controlArea.add(buttonPanel);

            // 状态显示
            statusLabel = new JLabel("就绪");
            statusLabel.setBorder(BorderFactory.createLoweredBevelBorder());
            controlArea.add(statusLabel);

            add(controlArea, BorderLayout.CENTER);

            setupEventListeners();
        }

        private String getDefaultInputData() {
            return "5 5\n" +
                    "0 0 1 0 0\n" +
                    "0 0 0 0 0\n" +
                    "0 0 1 0 1\n" +
                    "1 1 0 0 0\n" +
                    "0 0 0 1 0\n" +
                    "1 1 5 5";
        }

        private void setupEventListeners() {
            loadDataButton.addActionListener(e -> loadMazeData());
            startButton.addActionListener(e -> startSolving());
            pauseButton.addActionListener(e -> pauseSolving());
            resetButton.addActionListener(e -> resetSolving());
            stepButton.addActionListener(e -> stepSolving());

            speedSlider.addChangeListener(e -> {
                animationSpeed = speedSlider.getValue();
                if (timer != null) timer.setDelay(animationSpeed);
            });
        }

        private void loadMazeData() {
            String input = dataInputArea.getText();
            if (parseMazeData(input)) {
                resetSolvingState();
                mazePanel.setPreferredSize(new Dimension(cols * 40 + 100, rows * 40 + 100));
                revalidate();
                repaint();
                statusLabel.setText("迷宫数据加载成功: " + rows + "x" + cols);
            } else {
                JOptionPane.showMessageDialog(MazeSolverVisualization.this,
                        "数据格式错误！请检查输入格式。");
                statusLabel.setText("数据格式错误");
            }
        }

        private void startSolving() {
            isSolving = true;
            setSolvingStatus(true);
            timer.start();
            statusLabel.setText("求解中...");
        }

        private void pauseSolving() {
            isSolving = false;
            setSolvingStatus(false);
            timer.stop();
            statusLabel.setText("已暂停");
        }

        private void resetSolving() {
            timer.stop();
            isSolving = false;
            setSolvingStatus(false);
            resetSolvingState();
            updateDisplay();
            statusLabel.setText("已重置");
        }

        private void stepSolving() {
            timer.stop();
            solveStep();
            statusLabel.setText("单步执行");
        }

        public void setSolvingStatus(boolean solving) {
            startButton.setEnabled(!solving);
            pauseButton.setEnabled(solving);
            stepButton.setEnabled(!solving);
            loadDataButton.setEnabled(!solving);
            dataInputArea.setEnabled(!solving);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            } catch (Exception e) {
                e.printStackTrace();
            }
            new MazeSolverVisualization().setVisible(true);
        });
    }
}