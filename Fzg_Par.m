clc;
clear all;
close all;

load("Lap38Data.mat");

Ts = 1/10000;

% Geschwindigkeit
%--------------------------------------------------------------------------
v_x = 30/3.6;                   % [m/s] Längsgeschwindigkeit

% Massen
%--------------------------------------------------------------------------
m_fzg = 241.5 + 82;                % [kg] Gesamtfahrzeugmasse
J_fzg_z = 300;              % [kg*m^2] Massenträgheitsmoment um Z-Achse

% Schwerpunkt und geometrische Abmaße
%--------------------------------------------------------------------------
l_fzg = 1530/1000;               % [mm] Radstand Fahrzeug
l_V_fzg = 1023/1000;              % [mm] Schwerpunktvorlage
l_H_fzg = 507/1000;              % [mm] Schwerpunktrücklage
t_H_fzg = 1200/1000;                                                        % ======================

% Lenkung
%--------------------------------------------------------------------------
SAS = 82/100;
delta_L = 5;               % [°] Einlenkwinkel Lenkrad
i_L = 4.93;                 % [-] Lenkübersetzung
delta_V = 36 * SAS;      % [°] Spurwinkel Vorderrad
delta_S = delta_V;
delta_H = 0;                % [°] Spurwinkel Hinterrad

% Reifen
%--------------------------------------------------------------------------
c_alpha_V = 9300;          % [N/rad] Vorderreifenseitenachssteifigkeit
c_alpha_H = 13400;         % [N/rad] Hinterreifenseitenachssteifigkeit

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

% Schwerpunkt und geometrische Abmaße
%--------------------------------------------------------------------------
% EG = m_fzg * ((c_alpha_H * l_H_fzg) - (c_alpha_V * l_V_fzg))/(c_alpha_V * c_alpha_H * (l_V_fzg + l_H_fzg));                      % Einlenkgradient
% 
% v_x = linspace(0, 10, 1000);
% 
% yaw_rate_factor = 1/i_L .* v_x ./ ((l_V_fzg + l_H_fzg) + ((v_x.^2) * EG));
% 
% plot(v_x*3.6, yaw_rate_factor);                     % Funktion plotten
% xlabel('v_x [km/h]');
% ylabel('Gierverstärkung [Gierrate/Lenkwinkel');
% title('Giergeschwindigkeit/Lenkwinkel');
% grid on;
% 
% Kp = 2;
% Tn = 0.03;
% 
%Einspurmodell Zustandsraum
ss_A = [-(c_alpha_V*l_V_fzg^2+c_alpha_H*l_H_fzg^2)/(J_fzg_z*v_x) (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg)/J_fzg_z 
        (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg-m_fzg*v_x^2)/(m_fzg*v_x^2) -(c_alpha_V+c_alpha_H)/(m_fzg*v_x)];
ss_B = [(c_alpha_V*l_V_fzg)/J_fzg_z -(c_alpha_H*l_H_fzg)/J_fzg_z
        c_alpha_V/(m_fzg*v_x) c_alpha_H/(m_fzg*v_x)];
ss_C = [1 0];
ss_D = [0 0];
% 
% t_max = 10;
% delta_t = 0.001;
% k_max = t_max/delta_t;
% t_vec= zeros(1,k_max);
% x_1 = zeros(1,k_max);
% x_2 = zeros(1,k_max);
% 
% % Eingänge definieren
% delta_V = deg2rad(delta_L / 4.93);   % z. B. in rad, nicht °!
% delta_V_vec = zeros(1, k_max);
% delta_V_vec(1001:end) = delta_V;  % z. B. Sprung in den ersten 1000 Samples (1 s)
% 
% delta_H_vec = zeros(1, k_max);
% 
% psi_dot = zeros(1,k_max);
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


% hold on
% grid on
% xlabel('Zeit [sec]');
% ylabel('psi_dot [rad/sec]')
% plot(t_vec(1:k),psi_dot(1:k),'r')
% hold off 

% 
% v_vec = linspace(1, 60, 100); % Geschwindigkeitsbereich
% real_parts = zeros(2, length(v_vec)); % zwei Eigenwerte
% 
% for i = 1:length(v_vec)
%     v = v_vec(i);
%     A = [-(c_alpha_V*l_V_fzg^2+c_alpha_H*l_H_fzg^2)/(J_fzg_z*v)  (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg)/J_fzg_z
%          (c_alpha_H*l_H_fzg-c_alpha_V*l_V_fzg-m_fzg*v^2)/(m_fzg*v^2)  -(c_alpha_V+c_alpha_H)/(m_fzg*v)];
%     ev = eig(A);
%     real_parts(:, i) = real(ev);  % nur Realteile
% end
% 
% plot(v_vec, real_parts(1,:), 'r', v_vec, real_parts(2,:), 'b');
% xlabel('v_x [m/s]');
% ylabel('Realteil der Eigenwerte');
% grid on;
% legend('Eigenwert 1', 'Eigenwert 2');
% title('Stabilitätsanalyse des Einspurmodells');

