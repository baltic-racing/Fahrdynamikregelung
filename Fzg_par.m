clc;
clear all;
close all;

% Zeitkonstante
%--------------------------------------------------------------------------
delta_t = 1/1000;               % [sec] Zeitkonstante

% Geschwindigkeit
%--------------------------------------------------------------------------
v_x = 10;                   % [m/s] Längsgeschwindigkeit

% Massen
%--------------------------------------------------------------------------
m_fzg = 241.5 + 82;         % [kg] Gesamtfahrzeugmasse
J_fzg_z = 300;              % [kg*m^2] Massenträgheitsmoment um Z-Achse

% Schwerpunkt und geometrische Abmaße
%--------------------------------------------------------------------------
l_fzg = 1300/1000;         % [mm] Radstand Fahrzeug
l_V_fzg = 1023/1000;        % [mm] Schwerpunktvorlage
l_H_fzg = 507/1000;         % [mm] Schwerpunktrücklage

% Lenkung
%--------------------------------------------------------------------------
delta_L = -5;                % [°] Einlenkwinkel Lenkrad
i_L = 4.93;                 % [-] Lenkübersetzung
delta_V = delta_L/i_L;      % [°] Spurwinkel Vorderrad
delta_S = delta_V;
delta_H = 0;                % [°] Spurwinkel Hinterrad

% Reifen
%--------------------------------------------------------------------------
c_alpha_V = 9300;           % [N/rad] Vorderreifenseitenachssteifigkeit
c_alpha_H = 13400;          % [N/rad] Hinterreifenseitenachssteifigkeit


%Einspurmodell Zustandsraum
ss_A = [-(c_alpha_V*l_V_fzg^2+c_alpha_H*l_H_fzg^2)/(J_fzg_z*v_x) (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg)/J_fzg_z 
        (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg-m_fzg*v_x^2)/(m_fzg*v_x^2) -(c_alpha_V+c_alpha_H)/(m_fzg*v_x)];
ss_B = [(c_alpha_V*l_V_fzg)/J_fzg_z -(c_alpha_H*l_H_fzg)/J_fzg_z
        c_alpha_V/(m_fzg*v_x) c_alpha_H/(m_fzg*v_x)];
ss_C = [1 0];
ss_D = [0 0];

% 
% for k = 1 : k_max-1
% 
%     u1 = delta_V_vec(k);
%     u2 = delta_H_vec(k);
% 
%     x_1(k+1) = x_1(k)+delta_t*(ss_A(1,1)*x_1(k)+ss_A(1,2)*x_2(k)+ss_B(1,1)*u1+ss_B(1,2)*u2);
%     x_2(k+1) = x_2(k)+delta_t*(ss_A(2,1)*x_1(k)+ss_A(2,2)*x_2(k)+ss_B(2,1)*u1+ss_B(2,2)*u2);
%     psi_dot(k) = ss_C(1,1)*x_1(k)+ss_C(1,2)*x_2(k);
%     t_vec(k) = (k-1)*delta_t;
% 
% end