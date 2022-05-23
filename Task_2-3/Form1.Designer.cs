
namespace Task_2_3
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.PenGroupBox = new System.Windows.Forms.GroupBox();
            this.LabelFillColor = new System.Windows.Forms.Label();
            this.LabelPenColor = new System.Windows.Forms.Label();
            this.LabelWidth = new System.Windows.Forms.Label();
            this.FillColorValue = new System.Windows.Forms.ComboBox();
            this.PenColorValue = new System.Windows.Forms.ComboBox();
            this.PenWidthValue = new System.Windows.Forms.NumericUpDown();
            this.FigureGroupBox = new System.Windows.Forms.GroupBox();
            this.LabelCountPoint = new System.Windows.Forms.Label();
            this.CopuntPoint = new System.Windows.Forms.NumericUpDown();
            this.ChouseFigure = new System.Windows.Forms.ComboBox();
            this.SaveLoadGroupBox = new System.Windows.Forms.GroupBox();
            this.ButtonLoad = new System.Windows.Forms.Button();
            this.ButtonSave = new System.Windows.Forms.Button();
            this.UnReDoGroupBox = new System.Windows.Forms.GroupBox();
            this.ReDoButton = new System.Windows.Forms.Button();
            this.UnDoButton = new System.Windows.Forms.Button();
            this.Holst = new System.Windows.Forms.Panel();
            this.PenGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PenWidthValue)).BeginInit();
            this.FigureGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.CopuntPoint)).BeginInit();
            this.SaveLoadGroupBox.SuspendLayout();
            this.UnReDoGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // PenGroupBox
            // 
            this.PenGroupBox.Controls.Add(this.LabelFillColor);
            this.PenGroupBox.Controls.Add(this.LabelPenColor);
            this.PenGroupBox.Controls.Add(this.LabelWidth);
            this.PenGroupBox.Controls.Add(this.FillColorValue);
            this.PenGroupBox.Controls.Add(this.PenColorValue);
            this.PenGroupBox.Controls.Add(this.PenWidthValue);
            this.PenGroupBox.Location = new System.Drawing.Point(12, 12);
            this.PenGroupBox.Name = "PenGroupBox";
            this.PenGroupBox.Size = new System.Drawing.Size(250, 131);
            this.PenGroupBox.TabIndex = 1;
            this.PenGroupBox.TabStop = false;
            this.PenGroupBox.Text = "Pen";
            // 
            // LabelFillColor
            // 
            this.LabelFillColor.AutoSize = true;
            this.LabelFillColor.Location = new System.Drawing.Point(6, 96);
            this.LabelFillColor.Name = "LabelFillColor";
            this.LabelFillColor.Size = new System.Drawing.Size(68, 20);
            this.LabelFillColor.TabIndex = 14;
            this.LabelFillColor.Text = "Fill Color";
            // 
            // LabelPenColor
            // 
            this.LabelPenColor.AutoSize = true;
            this.LabelPenColor.Location = new System.Drawing.Point(6, 62);
            this.LabelPenColor.Name = "LabelPenColor";
            this.LabelPenColor.Size = new System.Drawing.Size(72, 20);
            this.LabelPenColor.TabIndex = 13;
            this.LabelPenColor.Text = "Pen Color";
            // 
            // LabelWidth
            // 
            this.LabelWidth.AutoSize = true;
            this.LabelWidth.Location = new System.Drawing.Point(6, 28);
            this.LabelWidth.Name = "LabelWidth";
            this.LabelWidth.Size = new System.Drawing.Size(49, 20);
            this.LabelWidth.TabIndex = 12;
            this.LabelWidth.Text = "Width";
            // 
            // FillColorValue
            // 
            this.FillColorValue.FormattingEnabled = true;
            this.FillColorValue.Items.AddRange(new object[] {
            "None",
            "Black",
            "Red",
            "Blue",
            "Green",
            "Violet",
            "Cyan",
            "Yellow",
            "Gray",
            "White",
            "DarkRed",
            "DarkBlue",
            "DarkGreen",
            "DarkViolet",
            "DarkCyan",
            "DarkGray"});
            this.FillColorValue.Location = new System.Drawing.Point(137, 93);
            this.FillColorValue.Name = "FillColorValue";
            this.FillColorValue.Size = new System.Drawing.Size(90, 28);
            this.FillColorValue.TabIndex = 11;
            this.FillColorValue.Text = "None";
            // 
            // PenColorValue
            // 
            this.PenColorValue.FormattingEnabled = true;
            this.PenColorValue.Items.AddRange(new object[] {
            "Black",
            "Red",
            "Blue",
            "Green",
            "Violet",
            "Cyan",
            "Yellow",
            "Gray",
            "White",
            "DarkRed",
            "DarkBlue",
            "DarkGreen",
            "DarkViolet",
            "DarkCyan",
            "DarkGray"});
            this.PenColorValue.Location = new System.Drawing.Point(137, 59);
            this.PenColorValue.Name = "PenColorValue";
            this.PenColorValue.Size = new System.Drawing.Size(90, 28);
            this.PenColorValue.TabIndex = 0;
            this.PenColorValue.Text = "Black";
            // 
            // PenWidthValue
            // 
            this.PenWidthValue.Location = new System.Drawing.Point(177, 26);
            this.PenWidthValue.Name = "PenWidthValue";
            this.PenWidthValue.ReadOnly = true;
            this.PenWidthValue.Size = new System.Drawing.Size(50, 27);
            this.PenWidthValue.TabIndex = 10;
            this.PenWidthValue.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // FigureGroupBox
            // 
            this.FigureGroupBox.Controls.Add(this.LabelCountPoint);
            this.FigureGroupBox.Controls.Add(this.CopuntPoint);
            this.FigureGroupBox.Controls.Add(this.ChouseFigure);
            this.FigureGroupBox.Location = new System.Drawing.Point(12, 149);
            this.FigureGroupBox.Name = "FigureGroupBox";
            this.FigureGroupBox.Size = new System.Drawing.Size(250, 107);
            this.FigureGroupBox.TabIndex = 13;
            this.FigureGroupBox.TabStop = false;
            this.FigureGroupBox.Text = "Figure";
            // 
            // LabelCountPoint
            // 
            this.LabelCountPoint.AutoSize = true;
            this.LabelCountPoint.Location = new System.Drawing.Point(6, 59);
            this.LabelCountPoint.Name = "LabelCountPoint";
            this.LabelCountPoint.Size = new System.Drawing.Size(103, 20);
            this.LabelCountPoint.TabIndex = 13;
            this.LabelCountPoint.Text = "Count of Point";
            // 
            // CopuntPoint
            // 
            this.CopuntPoint.Enabled = false;
            this.CopuntPoint.Location = new System.Drawing.Point(177, 57);
            this.CopuntPoint.Name = "CopuntPoint";
            this.CopuntPoint.ReadOnly = true;
            this.CopuntPoint.Size = new System.Drawing.Size(50, 27);
            this.CopuntPoint.TabIndex = 11;
            this.CopuntPoint.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // ChouseFigure
            // 
            this.ChouseFigure.FormattingEnabled = true;
            this.ChouseFigure.Location = new System.Drawing.Point(6, 26);
            this.ChouseFigure.Name = "ChouseFigure";
            this.ChouseFigure.Size = new System.Drawing.Size(90, 28);
            this.ChouseFigure.TabIndex = 0;
            this.ChouseFigure.Text = "Line";
            this.ChouseFigure.TextChanged += new System.EventHandler(this.ChouseFigure_TextChanged);
            // 
            // SaveLoadGroupBox
            // 
            this.SaveLoadGroupBox.Controls.Add(this.ButtonLoad);
            this.SaveLoadGroupBox.Controls.Add(this.ButtonSave);
            this.SaveLoadGroupBox.Location = new System.Drawing.Point(12, 262);
            this.SaveLoadGroupBox.Name = "SaveLoadGroupBox";
            this.SaveLoadGroupBox.Size = new System.Drawing.Size(120, 65);
            this.SaveLoadGroupBox.TabIndex = 14;
            this.SaveLoadGroupBox.TabStop = false;
            this.SaveLoadGroupBox.Text = "Save / Load";
            // 
            // ButtonLoad
            // 
            this.ButtonLoad.Location = new System.Drawing.Point(62, 26);
            this.ButtonLoad.Name = "ButtonLoad";
            this.ButtonLoad.Size = new System.Drawing.Size(50, 29);
            this.ButtonLoad.TabIndex = 1;
            this.ButtonLoad.Text = "Load";
            this.ButtonLoad.UseVisualStyleBackColor = true;
            this.ButtonLoad.Click += new System.EventHandler(this.ButtonLoad_Click);
            // 
            // ButtonSave
            // 
            this.ButtonSave.Location = new System.Drawing.Point(6, 26);
            this.ButtonSave.Name = "ButtonSave";
            this.ButtonSave.Size = new System.Drawing.Size(50, 29);
            this.ButtonSave.TabIndex = 0;
            this.ButtonSave.Text = "Save";
            this.ButtonSave.UseVisualStyleBackColor = true;
            this.ButtonSave.Click += new System.EventHandler(this.ButtonSave_Click);
            // 
            // UnReDoGroupBox
            // 
            this.UnReDoGroupBox.Controls.Add(this.ReDoButton);
            this.UnReDoGroupBox.Controls.Add(this.UnDoButton);
            this.UnReDoGroupBox.Location = new System.Drawing.Point(142, 262);
            this.UnReDoGroupBox.Name = "UnReDoGroupBox";
            this.UnReDoGroupBox.Size = new System.Drawing.Size(120, 65);
            this.UnReDoGroupBox.TabIndex = 15;
            this.UnReDoGroupBox.TabStop = false;
            this.UnReDoGroupBox.Text = "Undo / Redo";
            // 
            // ReDoButton
            // 
            this.ReDoButton.Location = new System.Drawing.Point(62, 26);
            this.ReDoButton.Name = "ReDoButton";
            this.ReDoButton.Size = new System.Drawing.Size(50, 29);
            this.ReDoButton.TabIndex = 1;
            this.ReDoButton.Text = ">";
            this.ReDoButton.UseVisualStyleBackColor = true;
            this.ReDoButton.MouseClick += new System.Windows.Forms.MouseEventHandler(this.ReDoButton_MouseClick);
            // 
            // UnDoButton
            // 
            this.UnDoButton.Location = new System.Drawing.Point(6, 26);
            this.UnDoButton.Name = "UnDoButton";
            this.UnDoButton.Size = new System.Drawing.Size(50, 29);
            this.UnDoButton.TabIndex = 0;
            this.UnDoButton.Text = "<";
            this.UnDoButton.UseVisualStyleBackColor = true;
            this.UnDoButton.MouseClick += new System.Windows.Forms.MouseEventHandler(this.UnDoButton_MouseClick);
            // 
            // Holst
            // 
            this.Holst.AutoSize = true;
            this.Holst.BackColor = System.Drawing.Color.White;
            this.Holst.Location = new System.Drawing.Point(279, 12);
            this.Holst.Name = "Holst";
            this.Holst.Size = new System.Drawing.Size(588, 499);
            this.Holst.TabIndex = 16;
            this.Holst.Paint += new System.Windows.Forms.PaintEventHandler(this.Holst_Paint);
            this.Holst.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Holst_MouseDown);
            this.Holst.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Holst_MouseMove);
            this.Holst.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Holst_MouseUp);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.ClientSize = new System.Drawing.Size(879, 523);
            this.Controls.Add(this.Holst);
            this.Controls.Add(this.UnReDoGroupBox);
            this.Controls.Add(this.SaveLoadGroupBox);
            this.Controls.Add(this.FigureGroupBox);
            this.Controls.Add(this.PenGroupBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.PenGroupBox.ResumeLayout(false);
            this.PenGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PenWidthValue)).EndInit();
            this.FigureGroupBox.ResumeLayout(false);
            this.FigureGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.CopuntPoint)).EndInit();
            this.SaveLoadGroupBox.ResumeLayout(false);
            this.UnReDoGroupBox.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox PenGroupBox;
        private System.Windows.Forms.Label LabelFillColor;
        private System.Windows.Forms.Label LabelPenColor;
        private System.Windows.Forms.Label LabelWidth;
        private System.Windows.Forms.ComboBox FillColorValue;
        private System.Windows.Forms.ComboBox PenColorValue;
        private System.Windows.Forms.NumericUpDown PenWidthValue;
        private System.Windows.Forms.GroupBox FigureGroupBox;
        private System.Windows.Forms.Label LabelCountPoint;
        private System.Windows.Forms.NumericUpDown CopuntPoint;
        private System.Windows.Forms.ComboBox ChouseFigure;
        private System.Windows.Forms.GroupBox SaveLoadGroupBox;
        private System.Windows.Forms.Button ButtonLoad;
        private System.Windows.Forms.Button ButtonSave;
        private System.Windows.Forms.GroupBox UnReDoGroupBox;
        private System.Windows.Forms.Button ReDoButton;
        private System.Windows.Forms.Button UnDoButton;
        private System.Windows.Forms.Panel Holst;
    }
}

