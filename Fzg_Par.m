
clc;
clear all;
close all;

load("TestData24.mat");

Ts = 1/10000;

% Geschwindigkeit
%--------------------------------------------------------------------------
v_x = 30/3.6;                   % [m/s] Längsgeschwindigkeit

% Massen
%--------------------------------------------------------------------------
m_fzg = 241.5 + 82;         % [kg] Gesamtfahrzeugmasse
m_Front = m_fzg * 0.4;      % [kg] Masse Front
m_Rear = m_fzg - m_Front;   % [kg] Masse Rear
J_fzg_z = 300;              % [kg*m^2] Massenträgheitsmoment um Z-Achse

% Schwerpunkt und geometrische Abmaße
%--------------------------------------------------------------------------
l_fzg = 1300/1000;          % [mm] Radstand Fahrzeug
l_V_fzg = 1023/1000;        % [mm] Schwerpunktvorlage
l_H_fzg = 507/1000;         % [mm] Schwerpunktrücklage
h_COG = 300/1000;           % [mm] Schwerpunkthöhe
t_V_fzg = 1250/1000;        % [mm] Spurweite Front
t_H_fzg = 1200/1000;        % [mm] Spurweite Rear

% Lenkung
%--------------------------------------------------------------------------
delta_L = -5;               % [°] Einlenkwinkel Lenkrad
i_L = 4.93;                 % [-] Lenkübersetzung
delta_V = delta_L/i_L;      % [°] Spurwinkel Vorderrad
delta_S = delta_V;
delta_H = 0;                % [°] Spurwinkel Hinterrad

% Reifen
%--------------------------------------------------------------------------
c_alpha_V = 9300;           % [N/rad] Vorderreifenseitenachssteifigkeit
c_alpha_H = 13400;          % [N/rad] Hinterreifenseitenachssteifigkeit
Dyn_Reifenradius = 0.23;    % [m] dynamischer Reifenradius
Sturzwinkel = 3;            % [°] Sturzwinkel
J_Rad = 0.2656;             % [kgm^2] Rotationsträgheit des Rades

% Aerodynamik
%--------------------------------------------------------------------------
c_DA = 3.9;                 % [m^2] Downforcekoeffizient*Anströmfläche
aero_balance_rear = 55/100; % [%] Aero Balance Rear

% Motor
%--------------------------------------------------------------------------
K_T = 0.62;                 % [Nm/A_rms] Torque Constant

% Reglerparameter
%--------------------------------------------------------------------------
K_G =1;
T_G =0.3;
G_G = tf (K_G,[T_G 1]);

K_H =1;
T_H =0.01;
G_H = tf (K_H,[T_H 1]);

K_PD = 5;
T_v = 0.1;
T_p = T_v/10; %parasitäre Verzögerung
%G_C = tf (K_C * [T_V 1], 1);

% Interaktives Reglerentwurfstool
%sisotool(G_G, G_C, G_H, tf(1, 1));

%Einspurmodell Zustandsraum
%--------------------------------------------------------------------------
ss_A = [-(c_alpha_V*l_V_fzg^2+c_alpha_H*l_H_fzg^2)/(J_fzg_z*v_x) (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg)/J_fzg_z 
        (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg-m_fzg*v_x^2)/(m_fzg*v_x^2) -(c_alpha_V+c_alpha_H)/(m_fzg*v_x)];
ss_B = [(c_alpha_V*l_V_fzg)/J_fzg_z -(c_alpha_H*l_H_fzg)/J_fzg_z
        c_alpha_V/(m_fzg*v_x) c_alpha_H/(m_fzg*v_x)];
ss_C = [1 0];
ss_D = [0 0];
