The Jupyter Notebook demonstrates the implementation and visualization of **Simple Linear Regression** from scratch using **Gradient Descent** in Python.

The dataset used in the notebook is perfectly linear, defined by the relation $Y = 180X - 360$.

Here is a step-by-step breakdown of what each section and cell in the notebook does:

---

### 1. Dataset Setup & Visualization

- **Cell 3 (Code)**: Sets up the training dataset:
  - `X_train` contains the input features: `[3, 4, 5, 10, 12]`
  - `Y_train` contains the corresponding ground-truth targets: `[180, 360, 540, 1440, 1800]`
  - `m` is the number of samples (`5`).
  - `x0` is a helper array of ones for the bias/intercept calculation.
- **Cell 4 (Code)**: Plots the training data using a scatter plot (`plt.scatter`) to show the initial distribution of the data.

---

### 2. Initial Predictions

- **Cell 6 (Code)**: Initializes the slope $w_1 = 0$ and intercept $w_0 = 0$.
  - It computes initial predictions: $Y_{pred} = w_1 X + w_0$ (which evaluates to $0$ for all $X$).
  - It plots a flat red line ($Y=0$) against the blue training scatter points to represent the untrained model.

---

### 3. Gradient Descent Implementations

The notebook implements Gradient Descent using three slightly different approaches to find the optimal weights $w_1$ (slope) and $w_0$ (intercept):

#### Approach A: Online/Stochastic Gradient Descent (Cell 7)

- Uses a learning rate $\alpha = 0.001$ and runs for $1000$ epochs.
- In each epoch, it iterates over each sample individually (online/stochastic gradient updates):
  $$\Delta w_1 = -(y_{actual} - y_{pred}) \cdot x$$
  $$\Delta w_0 = -(y_{actual} - y_{pred})$$
  $$w_j = w_j - \alpha \cdot \Delta w_j$$
- Because of the low learning rate and the small number of epochs ($1000$), it stops before fully converging, arriving at the approximate parameters:
  - $w_1 \approx 165.6981$
  - $w_0 \approx -231.2357$

#### Approach B: Batch Gradient Descent with Convergence Check (Cell 8)

- Formulates features as a 2D matrix (intercept column + feature column):
  `[[1, 3], [1, 4], [1, 5], [1, 10], [1, 12]]`
- Uses a learning rate $\alpha = 0.006$ and runs until the weights stop changing (convergence is reached).
- Accumulates the gradients over the entire batch before applying updates.
- Successfully converges to the exact mathematical solution in `6006` epochs:
  - $w_1 = 180.0$ (slope)
  - $w_0 = -360.0$ (intercept)

#### Approach C: Batch Gradient Descent with Loss Tracking (Cell 9)

- Implements batch gradient descent manually over the scalar variables `w0` and `w1` with a learning rate $\alpha = 0.005$.
- Keeps track of the Mean Squared Error (MSE) loss during training:
  $$\text{Loss} = \frac{1}{m} \sum_{i=1}^{m} (y_{pred}^{(i)} - y_{actual}^{(i)})^2$$
- Stops once convergence is reached, taking `4928` epochs to find the exact solution:
  - $w_1 = 180.0000$
  - $w_0 = -360.0000$

---

### 4. Final Predictions & Loss Visualization

- **Cell 10 (Code)**: Plots the final regression line (red) using the optimal weights learned ($Y = 180X - 360$). The line passes perfectly through all the blue data points.
- **Cell 12 (Code)**: Plots the convergence curve (`epochs` vs. `loss`) over time, showing how the MSE loss decreases rapidly and levels off to `0` as gradient descent finds the global minimum.

---

---

---

### 1. What Exactly is Gradient Descent?

**Gradient Descent** is an optimization algorithm used to minimize a function (usually a **Loss/Cost Function** in machine learning) by iteratively moving in the direction of steepest descent.

#### The Analogy:

Imagine you are blindfolded on top of a foggy mountain (representing high loss) and want to find the valley floor (representing the global minimum or the point of lowest loss).

1. Since you cannot see, you feel the slope of the ground under your feet (calculate the **gradient**).
2. If the slope is steep downward, you take a step in that direction.
3. The size of your step is controlled by your **learning rate** ($\alpha$).
   - If your steps are too large, you might overshoot the valley.
   - If your steps are too small, it will take you forever to reach the bottom.

#### The Mathematics:

In simple linear regression, we want to find the weight parameters $w$ that minimize our Loss function $L(w)$. The weight update rule is:

$$w_{\text{new}} = w_{\text{old}} - \alpha \frac{\partial L}{\partial w}$$

- **$\frac{\partial L}{\partial w}$ (The Gradient):** A vector of partial derivatives representing the slope of the loss function at the current parameter value.
- **$\alpha$ (Learning Rate):** A small positive scalar (e.g., $0.001$, $0.01$) that determines how large of a step we take.
- **The Minus Sign ($-$)**: Because the gradient points in the direction of the steepest _ascent_, we subtract it to move in the direction of the steepest _descent_.

---

### 2. How Does Gradient Descent Compare with the Perceptron Algorithm?

While both are fundamental machine learning concepts used to learn weights from data, they represent different categories: **Perceptron** is a specific _classifier algorithm_, whereas **Gradient Descent** is a general _optimization technique_.

| Feature                 | Gradient Descent                                                                      | Perceptron Algorithm                                                                                                 |
| :---------------------- | :------------------------------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------------- |
| **Primary Task**        | General-purpose optimizer (used for regression, classification, deep learning, etc.). | Binary classification ($0/1$ or $-1/1$) of linearly separable data.                                                  |
| **Output Type**         | Continuous numerical values (before thresholding).                                    | Discontinuous step outputs (hard threshold: yes/no).                                                                 |
| **Activation Function** | Differentiable functions (e.g., Identity, Sigmoid, Softmax, ReLU).                    | Non-differentiable **Heaviside Step Function** (has $0$ derivative everywhere except at $0$, where it is undefined). |
| **Loss Function**       | Continuous and differentiable (e.g., Mean Squared Error, Binary Cross-Entropy).       | Piecewise linear (Perceptron Criterion Loss).                                                                        |
| **Update Trigger**      | Updates parameters on every iteration based on the magnitude of the error.            | Updates weights **only** when it makes a misclassification.                                                          |
| **Convergence**         | Converges smoothly to the minimum for convex functions.                               | Converges in a finite number of steps _only if_ the data is linearly separable; otherwise, it loops indefinitely.    |

---

### 3. What is Regression & Regression Analysis?

**Regression Analysis** is a set of statistical methods used to estimate and model the relationships between variables. Specifically, it focuses on predicting a **continuous numerical output** (dependent variable/target, $Y$) based on one or more **input features** (independent variables, $X$).

- **Example:** Predicting house prices (continuous target $Y$ in dollars) based on square footage, number of bedrooms, and location zip code (features $X_1, X_2, X_3$).

#### Key Types of Regression:

1. **Simple Linear Regression:**
   Models the relationship between a single input feature $X$ and a target $Y$ using a straight line:
   $$Y = w_1 X + w_0$$
   _(This is exactly what was implemented in [Machine_Learning_Class.ipynb](file:///home/hz/file/git/uiu-code-archive/AI_LAB/8/Machine_Learning_Class.ipynb))_

2. **Multiple Linear Regression:**
   Extends simple regression to accommodate multiple input features:
   $$Y = w_0 + w_1 X_1 + w_2 X_2 + \dots + w_n X_n$$

3. **Polynomial / Non-linear Regression:**
   Models relationships that are curved rather than linear by raising independent variables to a power (e.g., $Y = w_2 X^2 + w_1 X + w_0$).

#### Regression vs. Classification:

- **Regression:** Predicts a continuous quantity (e.g., _"How much will it rain tomorrow?"_ $\rightarrow$ `2.4 inches`).
- **Classification:** Predicts a discrete class label (e.g., _"Will it rain tomorrow?"_ $\rightarrow$ `Yes / No`).
